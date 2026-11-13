class Solution
{
public:
    int n, x, k;

    long long memo[16][100001];

    long long minOps[100001];

    long long solve(int count, int i)
    {

        if (count == k)
            return 0;
        int subarrayNeeded = k - count;
        int elemNeeded = subarrayNeeded * x;
        int lastIndex = i + elemNeeded - 1;

        if (lastIndex >= n)
            return 1e16;

        if (memo[count][i] != -1)
            return memo[count][i];
        long long result = minOps[i] + solve(count + 1, i + x);

        result = min(result, solve(count, i + 1));

        return memo[count][i] = result;
    }

    long long minOperations(vector<int> &nums, int x, int k)
    {

        this->n = nums.size();
        this->x = x;
        this->k = k;

        memset(memo, -1, sizeof(memo));

        int i = 0, j = 0;

        multiset<int> left, right;

        long long leftSum = 0, rightSum = 0;

        while (j < n)
        {

            if (left.size() <= right.size())
            {
                left.insert(nums[j]);
                leftSum += nums[j];
            }
            else
            {
                right.insert(nums[j]);
                rightSum += nums[j];
            }

            if (!left.empty() && !right.empty())
            {
                int leftmax = *left.rbegin();
                int rightMin = *right.begin();

                if (leftmax > rightMin)
                {
                    left.erase(left.find(leftmax));
                    right.erase(right.find(rightMin));

                    left.insert(rightMin);
                    right.insert(leftmax);

                    leftSum += rightMin - leftmax;
                    rightSum += leftmax - rightMin;
                }
            }
            if (j - i + 1 == x)
            {

                long long median = *left.rbegin();
                long long leftOps = 0;
                long long rightOps = 0;

                long long leftSize = left.size();
                long long rightSize = right.size();

                leftOps = (leftSize * median) - leftSum;
                rightOps = rightSum - (rightSize * median);

                minOps[i] = leftOps + rightOps;
                if (left.find(nums[i]) != left.end())
                {
                    left.erase(left.find(nums[i]));
                    leftSum -= nums[i];
                }
                else
                {
                    right.erase(right.find(nums[i]));
                    rightSum -= nums[i];
                }
                i++;
            }
            j++;
        }

        return solve(0, 0);
    }
};