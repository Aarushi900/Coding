#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() <= 1)
        {
            return s.length();
        }
        int l = 0, r = 1;
        int ans = 1;
        vector<int> m(128, 0);
        m[s[0]] = 1;
        while (l <= r && r < s.length())
        {
            if (m[s[r]] > 0)
            {
                while (l <= r && s[l] != s[r])
                {
                    m[int(s[l])] = 0;
                    l++;
                }
                l++;
                cout << l;
            }
            else
            {
                m[s[r]] = 1;
                int temp = r - l + 1;
                // cout<<r<<endl<<l;
                ans = max(ans, temp);
            }
            r++;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s);
    return 0;
}