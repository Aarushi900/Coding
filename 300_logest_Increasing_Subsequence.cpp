#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int help(int index, vector<int> &nums, int prev_index, vector<vector<int>> &dp)
    {
        if (index == nums.size())
        {
            return 0;
        }
        if (dp[index][prev_index + 1] != -1)
        {
            return dp[index][prev_index + 1];
        }
        int not_take = 0 + help(index + 1, nums, prev_index, dp);

        int take = 0;
        if (prev_index == -1 || nums[index] > nums[prev_index])
        {
            take = 1 + help(index + 1, nums, index, dp);
        }
        return dp[index][prev_index + 1] = max(take, not_take);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return help(0, nums, -1, dp);
    }
};
// Another approach
class Solution2
{
public:
    int solveOptimal(vector<int> &arr)
    {
        if (arr.size() == 0)
        {
            return 0;
        }
        vector<int> ans;
        ans.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > ans.back())
            {
                // include
                ans.push_back(arr[i]);
            }
            else
            {
                // overwrite
                // find index just bada element
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int ans = 0;
        return ans = solveOptimal(nums);
    }
};
int main()
{
    Solution s;
    Solution2 s2;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int ans = s.lengthOfLIS(nums);
    int ans2 = s2.lengthOfLIS(nums);
    cout << ans;
    cout << ans2;
    return 0;
}