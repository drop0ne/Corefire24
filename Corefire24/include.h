#pragma once
#include <iostream>
#include <Windows.h>
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
#undef max()

using std::cin, std::cout, std::endl, std::getline, std::string;