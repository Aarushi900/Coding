#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &pre)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < pre.size(); i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
            indegree[pre[i][1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int k = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            k++;
            for (auto nxt : adj[curr])
            {
                indegree[nxt]--;
                if (indegree[nxt] == 0)
                {
                    q.push(nxt);
                }
            }
        }
        return k == numCourses;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> pre = {{1, 0}, {0, 1}};
    cout << s.canFinish(2, pre);
}