#pragma once

#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include <boost/preprocessor.hpp>

#define EXPOSE_MEMBERS_Q(M_ignore0, M_ignore1, M_member)        \
    BOOST_PP_STRINGIZE(M_member)

#define EXPOSE_MEMBERS(...)                                     \
    auto members() noexcept {                                   \
      return std::forward_as_tuple(__VA_ARGS__);                \
    }                                                           \
    auto members() const noexcept {                             \
      return std::forward_as_tuple(__VA_ARGS__);                \
    }                                                           \
    static constexpr auto names() noexcept {                    \
      return std::array{                                        \
        BOOST_PP_LIST_ENUM(                                     \
          BOOST_PP_LIST_TRANSFORM(                              \
            EXPOSE_MEMBERS_Q, @,                                \
            BOOST_PP_VARIADIC_TO_LIST(__VA_ARGS__)))};          \
    }

namespace std {
template <typename T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;
}

template <typename T>
concept bool Exposable = requires {
    std::declval<T>().members();
    std::declval<T>().names();
};
