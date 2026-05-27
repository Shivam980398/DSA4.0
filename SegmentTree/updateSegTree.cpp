

void updateSegTree(int i, int val, int l, int r, vector<int> &segTree)
{
    if (l == r)
    {
        segTree[i] = val;
        return;
    }

    int mid = l + (r - l) / 2;

    if (i <= mid)
    {
        updateSegTree(i, val, 2 * i + 1, l, mid, segTree);
    }
    else
    {
        updateSegTree(i, val, 2 * i + 2, mid + 1, r, segTree);
    }

    segTree[i] = segTree[2 * i + 1] + segTree(2 * i + 2);
}