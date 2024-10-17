#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
            {
                return {m[nums[i]], i};
            }
            m[target - nums[i]] = i;
        }
        return {};
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = sol.twoSum(nums, target);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}