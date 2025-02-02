#include "mergesort.h"
algoMergeSortParams mergeSortParams(800, 1);

void merge(std::vector<int>& arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            mergeSortParams.temp[k++] = arr[i++];
        }
        else
        {
            mergeSortParams.temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        mergeSortParams.temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        mergeSortParams.temp[k++] = arr[j++];
    }

    for (int p = left; p <= right; p++)
    {
        arr[p] = mergeSortParams.temp[p];
    }
}

void mergeSortStep(std::vector<int>& arr)
{
    if (mergeSortParams.isComplete) return;

    int n = arr.size();

    if (mergeSortParams.currentSize >= n)
    {
        mergeSortParams.isComplete = true;
        return;
    }

    int stepsPerformed = 0;
    while (stepsPerformed < mergeSortParams.elementsPerStep && mergeSortParams.leftStart < n - 1)
    {
        mergeSortParams.mid = std::min(mergeSortParams.leftStart + mergeSortParams.currentSize - 1, n - 1);
        mergeSortParams.rightEnd = std::min(mergeSortParams.leftStart + 2 * mergeSortParams.currentSize - 1, n - 1);

        merge(arr, mergeSortParams.leftStart, mergeSortParams.mid, mergeSortParams.rightEnd);

        mergeSortParams.leftStart += 2 * mergeSortParams.currentSize;
        stepsPerformed++;
    }

    if (mergeSortParams.leftStart >= n - 1)
    {
        mergeSortParams.currentSize *= 2;
        mergeSortParams.leftStart = 0;
    }
}