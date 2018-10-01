#pragma once

#define CONCAT(x, y) x ## y

#define CONCAT_DEBUG(x, y)                      \
  _Pragma(#x)                                   \
  _Pragma(#y)                                   \
  x ## y
