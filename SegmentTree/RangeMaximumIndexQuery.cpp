#include <bits/stdc++.h>
using namespace std;

void BuildSegTree(int i, int l, int r, int *SegTree, vector<int> &nums)
{
    if (l == r)
    {
        SegTree[i] = l;
        return;
    }

    int mid = l + (r - l) / 2;

    BuildSegTree(2 * i + 1, l, mid, SegTree, nums);
    BuildSegTree(2 * i + 2, mid + 1, r, SegTree, nums);

    int leftMaxIdx = SegTree[2 * i + 1];
    int rightMaxIdx = SegTree[2 * i + 2];
    SegTree[i] = max(leftMaxIdx, rightMaxIdx);
}

int queryMaximum(int start, int end, int i, int l, int r, int *SegTree, vector<int> &nums)
{

    if (l > end || r < start)
    {
        return -1;
    }

    if (l >= start && r <= end)
    {
        return SegTree[i];
    }

    int mid = l + (r - l) / 2;

    int leftMaxIdx = queryMaximum(start, end, 2 * i + 1, l, mid, SegTree, nums);
    int rightMaxIdx = queryMaximum(start, end, 2 * i + 2, mid + 1, r, SegTree, nums);

    if (leftMaxIdx == -1)
    {
        return rightMaxIdx;
    }
    if (rightMaxIdx == -1)
    {
        return leftMaxIdx;
    }
    if (nums[leftMaxIdx] >= nums[rightMaxIdx])
    {
        return leftMaxIdx;
    }

    return rightMaxIdx;
}

int main()
{
    int n;

    vector<int> nums = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    n = nums.size();
    int *SegTree = new int[4 * n];

    BuildSegTree(0, 0, n - 1, SegTree, nums);

    cout << queryMaximum(0, 5, 0, 0, n - 1, SegTree, nums);
}