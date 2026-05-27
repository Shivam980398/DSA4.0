

#include <bits/stdc++.h>
using namespace std;

void buildSegTree(int i, int l, int r)
{

    if (l == r)
    {
        segTree[i] = nums[i];
        return;
    }
    int mid = (l + r) / 2;

    buildSegTree(2 * i + 1, l, mid);
    buildSegTree(2 * i + 2, mid + 1, r);

    segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
}

int main()
{
}