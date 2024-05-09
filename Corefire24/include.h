#pragma once
#undef max()
//#define NOMAXMIN // This is a macro that prevents the min and max macros from being defined
#include <windows.h> // Ensure this is included in your project for console functions
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <any>
#include <string>
#include <limits>
#include <stdexcept>

#include "Utility.h"
#include "MyConsoleAPI.h"
#include "MyFunctions.h"


// this resolves conflit of two definitions

// Path: Corefire24/include.cpp