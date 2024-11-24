#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
// Optimal approach
class Solution2
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m1 = text1.length();
        int m2 = text2.length();
        vector<int> curr(m2 + 1, 0), prev(m2 + 1, 0);
        for (int i = 1; i <= m1; i++)
        {
            for (int j = 1; j <= m2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return curr[m2];
    }
};
int main()
{
    Solution s;
    Solution2 s2;
    cout << s.longestCommonSubsequence("abcde", "ace") << endl;
    cout << s2.longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}