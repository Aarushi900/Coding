#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    // counts number of integers less than or equal to x in multiplication table
    int count(int m, int n, int x)
    {
        int ans = 0;
        for (int i = 1; i <= m; i++)
            ans += min(x / i, n);
        return ans;
    }
    int findKthNumber(int m, int n, int k)
    {
        int L = 1, R = m * n, mid, ans;
        while (L <= R)
        {
            mid = (L + R) >> 1;
            if (count(m, n, mid) < k)
                L = mid + 1;
            else
                R = mid - 1, ans = mid;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.findKthNumber(3, 3, 5);
    cout << "hello";
    return 0;
}