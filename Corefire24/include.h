#pragma once
#include <iostream>
#define NOMAXMIN // This is a macro that prevents the min and max macros from being defined	
#include <algorithm>
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
//#undef max()

// Path: Corefire24/include.cpp