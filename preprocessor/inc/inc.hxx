#pragma once

#include <concat.hxx>
#include <inc.ixx>

#define INC(x) INC_I(x)
#define INC_I(x) CONCAT(INC_BOOM_, x)
