#pragma once

#include "concat.hxx"
#include "sum.ixx"

#define SUM(x, y)    SUM_I(x, y)
#define SUM_I(x, y)  SUM_II(CONCAT(SUM_BOOM_, x), CONCAT(_, y))
#define SUM_II(x, y) CONCAT(x, y)
