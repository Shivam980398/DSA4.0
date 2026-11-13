#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMedian(vector<int> &nums, int X)
{
    vector<int> medians;
    multiset<int> left, right;
    int i = 0, j = 0, n = nums.size();

    while (j < n)
    {
        // Insert new element into the sliding window
        if ((int)left.size() <= (int)right.size())
        {
            left.insert(nums[j]);
        }
        else
        {
            right.insert(nums[j]);
        }

        int leftSize = left.size();
        int rightSize = right.size();

        // Balance multisets to maintain median
        while (leftSize > 0 && rightSize > 0)
        {
            int leftMax = *left.rbegin();
            int rightMin = *right.begin();
            if (leftMax > rightMin)
            {
                // Swap elements to restore balance
                left.insert(rightMin);
                right.insert(leftMax);
                left.erase(left.find(leftMax));
                right.erase(right.find(rightMin));
                leftSize = left.size();
                rightSize = right.size();
            }
            else
            {
                break;
            }
        }

        // Check if we have a valid subarray
        if (j - i + 1 == X)
        {
            int median = *left.rbegin();
            medians.push_back(median);

            // Remove the leftmost element as we slide forward
            if (left.find(nums[i]) != left.end())
            {
                left.erase(left.find(nums[i]));
            }
            else
            {
                right.erase(right.find(nums[i]));
            }
            i++;
        }
        j++;
    }
    return medians;
}

int main()
{
    vector<int> nums = {5, -2, 1, 3, 7, 3, 6, 4, -1};
    int X = 5;
    vector<int> medians = slidingWindowMedian(nums, X);

    for (int median : medians)
        cout << median << " ";
    cout << endl;
    return 0;
}