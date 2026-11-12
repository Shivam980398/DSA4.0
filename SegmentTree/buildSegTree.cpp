

#include <bits/stdc++.h>
using namespace std;

void BuildSegTree(int i, int l, int r, vector<int> &SegTree, vector<int> &nums)
{
    if (l == r)
    {
        SegTree[i] = nums[i];
        return;
    }
    int mid = l + (r - l) / 2;
    BuildSegTree(2 * i + 1, l, mid, SegTree, nums);
    BuildSegTree(2 * i + 2, mid + 1, r, SegTree, nums);

    SegTree[i] = SegTree[2 * i + 1] + SegTree[2 * i + 2];
}

int main()
{
}