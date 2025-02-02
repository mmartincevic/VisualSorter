#pragma once

#include <vector>
#include <iostream>

struct algoMergeSortParams
{
    std::vector<int> temp;
    int currentSize;
    int leftStart;
    int rightEnd;
    int mid;
    int elementsPerStep;
    int i, j, k;
    bool isComplete;
    algoMergeSortParams(int size, int step) : temp(size), currentSize(1), leftStart(0), rightEnd(0), mid(0), i(0), j(0), k(0), isComplete(false), elementsPerStep(step) {}
};
extern algoMergeSortParams mergeSortParams;
void mergeSortStep(std::vector<int>& arr);
void merge(std::vector<int>& arr, int left, int mid, int right);