#pragma once

#include "boolean.hxx"
#include "compl.hxx"

#define EQUALS(x, y) COMPL(BOOLEAN(SUB(x, y)))
