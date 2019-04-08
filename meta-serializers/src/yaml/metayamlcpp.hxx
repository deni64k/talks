#pragma once

#include "common.hxx"

#include <yaml-cpp/yaml.h>

namespace { namespace details {

template <typename T> struct yamlcpp_encoder_impl {
  static YAML::Emitter&
  call(YAML::Emitter& out, T const& value) {
    out << value;
    return out;
  }
};

template <Exposable T> struct yamlcpp_encoder_impl<T> {
  static YAML::Emitter&
  call(YAML::Emitter& out, T const& obj) {
    out << YAML::BeginMap;

    std::apply([&](auto const& names, auto const&... members) {
      unsigned i = 0;

      ((out << YAML::Key << names[i++]
            << YAML::Value,
        yamlcpp_encoder_impl<std::remove_cvref_t<decltype(members)>>::call(out, members)),
        ...);
    }, std::tuple_cat(std::make_tuple(obj.names()), obj.members()));

    out << YAML::EndMap;

    return out;
  }
};

template <typename T> struct yamlcpp_encoder_impl<std::vector<T>> {
  static YAML::Emitter&
  call(YAML::Emitter& out, std::vector<T> const& objs) {
    out << YAML::BeginSeq;

    for (auto const& obj : objs) {
      yamlcpp_encoder_impl<std::remove_cvref_t<T>>::call(out, obj);
    }

    out << YAML::EndSeq;

    return out;
  }
};

} // namespace details

template <typename T>
std::string metayamlcpp_encoder(T const& obj) {
  YAML::Emitter out;

  details::yamlcpp_encoder_impl<T>::call(out, obj);

  return {out.c_str()};
}

} // namespace
