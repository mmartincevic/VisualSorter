#include "radixsort.h"

algoRadixSortParams radixSortParams{ 0, 1, 0, false };

int getMax(const std::vector<int>& arr)
{
    int mx = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(std::vector<int>& arr, int exp)
{
    std::vector<int> output(arr.size());
    int count[10] = { 0 };

    for (int i : arr)
        count[(i / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    arr = output;
}

bool radixSortStep(std::vector<int>& arr)
{
    if (radixSortParams.stepCount == 0)
    {
        radixSortParams.maxVal = getMax(arr);
    }

    if (radixSortParams.maxVal / radixSortParams.currentExp == 0)
    {
        radixSortParams.isComplete = true;
        return false;
    }

    countSort(arr, radixSortParams.currentExp);
    radixSortParams.currentExp *= 10;
    radixSortParams.stepCount++;

    return true;
}

void resetRadixSort()
{
    radixSortParams = { 0, 1, 0, false };
}