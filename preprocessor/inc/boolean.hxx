#pragma once

#include "concat.hxx"
#include "boolean.ixx"

#define BOOLEAN(x)   BOOLEAN_I(x)
#define BOOLEAN_I(x) CONCAT(BOOLEAN_BOOM_, x)
