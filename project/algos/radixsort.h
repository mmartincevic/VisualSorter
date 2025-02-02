#pragma once
#include <vector>
#include <iostream>

struct algoRadixSortParams
{
    int maxVal;
    int currentExp;
    int stepCount;
    bool isComplete;
};

extern algoRadixSortParams radixSortParams;

int getMax(const std::vector<int>& arr);
void countSort(std::vector<int>& arr, int exp);
bool radixSortStep(std::vector<int>& arr);
void resetRadixSort();