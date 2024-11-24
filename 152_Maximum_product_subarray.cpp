#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int max_left = INT_MIN;
        int max_right = INT_MIN;
        int temp_product = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            temp_product *= nums[i];
            max_left = max(temp_product, max_left);
            if (temp_product == 0)
            {
                temp_product = 1;
            }
        }
        temp_product = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            temp_product *= nums[i];
            max_right = max(temp_product, max_right);
            if (temp_product == 0)
            {
                temp_product = 1;
            }
        }
        return max(max_left, max_right);
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 3, -2, 4};
    cout << s.maxProduct(nums);
}