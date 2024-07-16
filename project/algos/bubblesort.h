#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

struct algoBubbleSortParams
{
    int innerLoopCounter = 0;
    int outerLoopCounter = 0;
};


bool bubbleSortStep(std::vector<int>& arr);