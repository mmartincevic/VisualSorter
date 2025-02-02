#include "cyclesort.h"


algoCycleSortParams cycleSortParams;

bool cycleSortStep(std::vector<int>& arr, int N)
{
    int n = arr.size();

    if (cycleSortParams.cycle_start >= n - 1)
    {
        return false;
    }

    for (int step = 0; step < N; ++step)
    {
        if (cycleSortParams.state == 0)
        {
            cycleSortParams.item = arr[cycleSortParams.cycle_start];
            cycleSortParams.pos = cycleSortParams.cycle_start;
            cycleSortParams.i = cycleSortParams.cycle_start + 1;
            cycleSortParams.state = 1;
        }

        if (cycleSortParams.state == 1)
        {
            int end = std::min(cycleSortParams.i + N, n);
            for (; cycleSortParams.i < end; ++cycleSortParams.i)
            {
                if (arr[cycleSortParams.i] < cycleSortParams.item)
                {
                    cycleSortParams.pos++;
                }
            }
            if (cycleSortParams.i >= n)
            {
                cycleSortParams.state = 2;
            }
        }

        if (cycleSortParams.state == 2)
        {
            if (cycleSortParams.pos == cycleSortParams.cycle_start)
            {
                cycleSortParams.cycle_start++;
                cycleSortParams.state = 0;
                if (cycleSortParams.cycle_start >= n - 1)
                {
                    return false;
                }
            }
            else
            {
                cycleSortParams.state = 3;
            }
        }

        if (cycleSortParams.state == 3)
        {
            if (cycleSortParams.item == arr[cycleSortParams.pos])
            {
                cycleSortParams.pos++;
            }
            else
            {
                std::swap(cycleSortParams.item, arr[cycleSortParams.pos]);
                cycleSortParams.state = 0;
            }
        }
    }

    return true;
}