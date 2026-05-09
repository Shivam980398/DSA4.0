#include <bits/stdc++.h>
using namespace std;

int triangularSum(vector<int> &nums)
{
    int n = nums.size();

    while (n > 1)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
        }
        --n;
    }

    return nums[0];
}

int triangularSum2(vector<int> &nums)
{
    int n = nums.size();
    int res = 0;
    int coeff = 1;

    for (int i = 0; i < n; ++i)
    {
        res = (res + coeff * nums[i]) % 10;

        // Update binomial coefficient using Pascal's rule
        coeff = coeff * (n - 1 - i) / (i + 1);
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << triangularSum2(nums) << endl;
    return 0;
}