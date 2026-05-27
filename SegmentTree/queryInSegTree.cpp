

int queryInSegTree(int start, int end, int i, int l, int r, vector<int> &segTree)
{

    if (l > end || r < start)
        return 0;

    if (l >= start && r <= end)
    {
        return segTree[i];
    }

    int mid = l + (r - l) / 2;

    return queryInSegTree(start, end, 2 * i + 1, l, mid, segTree) + queryInSegTree(start, end, 2 * i + 2, mid + 1, r, segTree);
}