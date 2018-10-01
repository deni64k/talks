#pragma once

#include "concat.hxx"
#include "sub.ixx"

#define SUB(x, y)    SUB_I(x, y)
#define SUB_I(x, y)  SUB_II(CONCAT(SUB_BOOM_, x), CONCAT(_, y))
#define SUB_II(x, y) CONCAT(x, y)
