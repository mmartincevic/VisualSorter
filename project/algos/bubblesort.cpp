#include "bubblesort.h"


algoBubbleSortParams bubbleSortParams{ 0, 0 };

bool bubbleSortStep(std::vector<int>& arr)
{
    if (bubbleSortParams.outerLoopCounter >= arr.size() - 1)
    {
        return false;
    }

    bool swapped = false;

    if (bubbleSortParams.innerLoopCounter < arr.size() - bubbleSortParams.outerLoopCounter - 1)
    {
        if (arr[bubbleSortParams.innerLoopCounter] > arr[bubbleSortParams.innerLoopCounter + 1])
        {
            std::swap(arr[bubbleSortParams.innerLoopCounter], arr[bubbleSortParams.innerLoopCounter + 1]);
            swapped = true;
        }
        bubbleSortParams.innerLoopCounter++;
    }
    else
    {
        bubbleSortParams.innerLoopCounter = 0;
        bubbleSortParams.outerLoopCounter++;
        if (!swapped)
        {
            return false;
        }
    }

    return true;
}