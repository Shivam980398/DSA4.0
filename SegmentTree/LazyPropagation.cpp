

void updateRange(int Start, int End, int i, int l, int r, int val, vector<int> segTree, vector<int> lazyTree)
{

    if (lazyTree[i] != 0)
    {
        segTree[i] += (lazyTree[i]);

        if (l != r)
        {
            segTree[2 * i + 1] += lazyTree[i];
            segTree[2 * i + 2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }

    // out of bound
    if (Start > r || End < l || l > r)
        return;

    // in between range
    if (start <= l || End >= r)
    {

        segTree[i] += (r - l + 1) * val;

        if (l != r)
        {
            lazyTree[2 * i + 1] += val;
            lazyTree[2 * i + 2] += val;
        }
        return;
    }

    // overlapping

    int mid = l + (r - l) / 2;

    updateRange(Start, End, 2 * i + 1, l, mid, val, segTree, lazyTree);
    updateRange(Start, End, 2 * i + 2, mid + 1, r, val, segTree, lazyTree);

    segTree[i] += segTree[2 * i + 1] + segTree[2 * i + 2]
}