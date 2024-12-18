#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> right(n, 0);
        vector<int> left(n, 0);
        int ans = 0;
        left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], height[i]);
            ans += (min(left[i], right[i]) - height[i]);
        }
        ans += (min(left[0], right[0]) - height[0]);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << sol.trap(height);
    cout << "hello";
    return 0;
}