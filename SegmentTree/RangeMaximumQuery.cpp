#include <bits/stdc++.h>
using namespace std;

void BuildSegTree(int i, int l, int r, int *SegTree, vector<int> &nums)
{
    if (l == r)
    {
        SegTree[i] = nums[l];
        return;
    }

    int mid = l + (r - l) / 2;
    BuildSegTree(2 * i + 1, l, mid, SegTree, nums);
    BuildSegTree(2 * i + 2, mid + 1, r, SegTree, nums);

    SegTree[i] = max(SegTree[2 * i + 1], SegTree[2 * i + 2]);
}

int queryMaximum(int start, int end, int i, int l, int r, int *SegTree, vector<int> &nums)
{
    if (l > end || r < start)
        return INT_MIN;

    if (l >= start && r <= end)
        return SegTree[i];

    int mid = l + (r - l) / 2;

    return max(queryMaximum(start, end, 2 * i + 1, l, mid, SegTree, nums),
               queryMaximum(start, end, 2 * i + 2, mid + 1, r, SegTree, nums));
}

int main()
{
    int n;

    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    n = nums.size();
    int *SegTree = new int[4 * n];

    BuildSegTree(0, 0, n - 1, SegTree, nums);

    cout << queryMaximum(2, n - 1, 0, 0, n - 1, SegTree, nums);
}