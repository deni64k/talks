#pragma once

#include <concat.hxx>
#include <dec.ixx>

#define DEC(x) DEC_I(x)
#define DEC_I(x) CONCAT(DEC_BOOM_, x)
