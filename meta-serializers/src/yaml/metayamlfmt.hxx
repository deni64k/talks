#pragma once

#include "common.hxx"

#include <format>

namespace { namespace details {

std::string_view to_sv(fmt::memory_buffer&& buf) {
  return std::string_view{buf.data(), buf.size()};
}

template <typename T> struct yaml_encoder_impl {
  static fmt::memory_buffer&
  call(fmt::memory_buffer& out, std::size_t align, T const& value) {
    std::string spaces(align, ' ');

    fmt::format_to(out, fmt("\n{:s}{}"), spaces, value);

    return out;
  }
};

template <Exposable T> struct yaml_encoder_impl<T> {
  static fmt::memory_buffer&
  call(fmt::memory_buffer& out, std::size_t align, T const& obj) {
    std::string spaces(align, ' ');

    std::apply([&](auto const& names, auto const&... members) {
      unsigned i = 0;

      ((fmt::format_to(out, fmt("\n{:s}{:s}:"), spaces, names[i++]),
        yaml_encoder_impl<std::remove_cvref_t<decltype(members)>>::call(out, align + 2, members)),
        ...);
    }, std::tuple_cat(std::make_tuple(obj.names()), obj.members()));

    return out;
  }
};

template <typename T> struct yaml_encoder_impl<std::vector<T>> {
  static fmt::memory_buffer&
  call(fmt::memory_buffer& out, std::size_t align, std::vector<T> const& objs) {
    std::string spaces(align, ' ');

    for (auto const& obj : objs) {
      fmt::format_to(out, fmt("\n{:s}-"), spaces);
      yaml_encoder_impl<std::remove_cvref_t<T>>::call(out, align + 2, obj);
    }

    return out;
  }
};

} // namespace details

template <typename T>
std::string metayamlfmt_encoder(T const& obj) {
  fmt::memory_buffer out;
  details::yaml_encoder_impl<T>::call(out, 0, obj);
  return fmt::to_string(out);
}

} // namespace
