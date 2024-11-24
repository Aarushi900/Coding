#include <bits/stdc++.h>
using namespace std;
int help(vector<vector<int>> &dp, int w, vector<int> &wei, vector<int> &val, int index)
{
    if (index < 0)
    {
        return 0;
    }
    if (dp[w][index] != -1)
    {
        return dp[w][index];
    }
    if (wei[index] > w)
    {
        dp[w][index] = help(dp, w, wei, val, index - 1);
    }
    else
    {
        dp[w][index] = max(val[index] + help(dp, w - wei[index], wei, val, index - 1), help(dp, w, wei, val, index - 1));
    }
    return dp[w][index];
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    vector<vector<int>> dp(w + 1, vector<int>(n, -1));
    return help(dp, w, weights, values, n - 1);
}
int main()
{
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int n = 3;
    int w = 50;
    cout << maxProfit(values, weights, n, w);
}