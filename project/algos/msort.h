#include <vector>
#include <stack>
#include "SortState.h"

struct MergeSortState
{
    std::vector<int>& arr;
    std::stack<std::pair<int, int>> ranges;
    int left, right, mid;
    enum Stage { DIVIDE, MERGE, COPY } stage;
    std::vector<int> temp;
    int i, j, k;

    MergeSortState(std::vector<int>& a) : arr(a), left(0), right(a.size() - 1),
        stage(DIVIDE), temp(a.size())
    {
        ranges.push({ left, right });
    }
};

class MySortState : public ISortState
{
public:
    MySortState(std::vector<int>& a) : m_state(a) {}

public:
    MergeSortState& getState() { return m_state; }

private:
    MergeSortState m_state;
};

bool mergeSortStep2(MySortState* s)
{
    MergeSortState& state = s->getState();
    if (state.ranges.empty() && state.stage == MergeSortState::DIVIDE)
    {
        return false; // Sorting is complete
    }
    switch (state.stage)
    {
    case MergeSortState::DIVIDE:
        if (state.ranges.empty())
        {
            state.ranges.push({ 0, state.arr.size() - 1 });
        }
        if (state.ranges.top().first >= state.ranges.top().second)
        {
            state.ranges.pop();
            return true;
        }
        state.left = state.ranges.top().first;
        state.right = state.ranges.top().second;
        state.mid = state.left + (state.right - state.left) / 2;
        state.ranges.pop();
        if (state.left < state.mid)
            state.ranges.push({ state.left, state.mid });
        if (state.mid + 1 < state.right)
            state.ranges.push({ state.mid + 1, state.right });
        state.stage = MergeSortState::MERGE;
        break;
    case MergeSortState::MERGE:
        state.i = state.left;
        state.j = state.mid + 1;
        state.k = state.left;
        state.stage = MergeSortState::COPY;
        break;
    case MergeSortState::COPY:
        if (state.k > state.right)
        {
            for (int p = state.left; p <= state.right; p++)
            {
                state.arr[p] = state.temp[p];
            }
            state.stage = MergeSortState::DIVIDE;
            return true;
        }
        if (state.i <= state.mid && (state.j > state.right || state.arr[state.i] <= state.arr[state.j]))
        {
            state.temp[state.k++] = state.arr[state.i++];
        }
        else
        {
            state.temp[state.k++] = state.arr[state.j++];
        }
        break;
    }
    return true;
}