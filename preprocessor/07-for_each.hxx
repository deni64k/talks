#include "inc/concat.hxx"
#include "inc/stringize.hxx"

#define EXPAND(...)          __VA_ARGS__
#define EXPAND2(...) EXPAND (__VA_ARGS__)
#define EXPAND3(...) EXPAND2(__VA_ARGS__)

#define EMPTY()
#define DEFER(m) m EMPTY() ()

#define FOR_EACH_PASSIVE() FOR_EACH_I
#define FOR_EACH(m, ...)   EXPAND(FOR_EACH_I(m, __VA_ARGS__))
#define FOR_EACH_I(m, ...) CONCAT(FOR_EACH_BOOM_, __VA_OPT__(1))(m, __VA_ARGS__)
#define FOR_EACH_BOOM_1(m, arg, ...)            \
  m(arg)                                        \
  DEFER(FOR_EACH_PASSIVE)(m, __VA_ARGS__)
#define FOR_EACH_BOOM_(m, ...)

FOR_EACH(Q, 1, 2, 3)           //-> "1" "2" FOR_EACH_PASSIVE ()(Q, 3)
EXPAND (FOR_EACH(Q, 1, 2, 3))  //-> "1" "2" "3" FOR_EACH_PASSIVE ()(Q, )
EXPAND2(FOR_EACH(Q, 1, 2, 3))  //-> "1" "2" "3"
EXPAND3(FOR_EACH(Q, 1, 2, 3))  //-> "1" "2" "3"
