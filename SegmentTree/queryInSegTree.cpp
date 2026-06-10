

int queryInSegTree(int start, int end, int i, int l, int r, vector<int> &segTree)
{

    //    eg root node  l =0 , r=7
    //  query    start = 2 end =7

    //    0>7 || 7<2   false
    if (l > end || r < start)
        return 0;

    // 0>=2 (F)&& 7<=7(T) ->F
    if (l >= start && r <= end)
    {
        return segTree[i];
    }

    // overlapping i.e half part exist in left and half in right
    int mid = l + (r - l) / 2;

    return queryInSegTree(start, end, 2 * i + 1, l, mid, segTree) + queryInSegTree(start, end, 2 * i + 2, mid + 1, r, segTree);
}