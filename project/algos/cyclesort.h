#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

struct algoCycleSortParams
{
    int cycle_start = 0;
    int pos = 0;
    int item = 0;
    int i = 0;
    int state = 0;
};

extern algoCycleSortParams cycleSortParams;

bool cycleSortStep(std::vector<int>& arr, int N);
