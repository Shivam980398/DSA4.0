#include <bits/stdc++.h>

using namespace std;
long long solve(vector<int> &nums, int i, int n, bool isEven)
{
    if (i >= n)
        return 0;

    int val = nums[i];

    if (!isEven)
        val = -val;

    int take = val + solve(nums, i + 1, n, !isEven);
    int skip = solve(nums, i + 1, n, isEven);

    return max(take, skip);
}
long long maxAlternatingSubsequenceSum(vector<int> &nums)
{

    int n = nums.size();
    return solve(nums, 0, n, true);
}

int main()
{

    vector<int> nums = {4, 2, 5, 3};

    cout << maxAlternatingSubsequenceSum(nums);
}