#pragma once

#include "Script.h"
#include <map>

gSScriptInit & GetScriptInit();

static std::map<gEUseType , bCString> useTypeMap;
static void InitMap ( );