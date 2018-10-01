#pragma once

#include "concat.hxx"
#include "boolean.hxx"

#define COMPL(x)   COMPL_I(BOOLEAN(x))
#define COMPL_I(x) CONCAT(COMPL_BOOM_, x)

#define COMPL_BOOM_0 1
#define COMPL_BOOM_1 0
