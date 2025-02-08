#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> graph;
    vector<bool> vis;
    int ans = 0;
    void dfs(int vertix, int start_node, vector<int> &vals)
    {
        vis[vertix] = true;
        for (auto var : graph[vertix])
        {
            // cout<<vertix<<" "<<var<<endl;
            if (!vis[var])
            {

                if (vals[var] == vals[start_node])
                {
                    ans++;

                    // cout<<var<<vertix<<start_node<<endl;
                }
                if (vals[var] > vals[start_node])
                {

                    continue;
                }
                // if (vals[var] <= vals[start_node])
                // {
                dfs(var, start_node, vals);

                // }
            }
        }
    }
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        int n = vals.size();
        graph.resize(n);
        vis.resize(n, false);
        // cout<<n;
        for (auto var : edges)
        {
            graph[var[0]].push_back(var[1]);
            graph[var[1]].push_back(var[0]);
        }
        int sum = 0;
        // dfs(0,0,vals);
        // cout<<graph[0][0];
        map<int, int> mp;
        for (auto var : vals)
        {
            mp[var]++;
        }
        // for(auto var : mp)
        // {
        //     cout<<var.first<<var.second<<endl;
        // }

        for (int i = 0; i < n; i++)
        {
            int node_value = vals[i];
            if (mp[node_value] > 1)
            {   
                // cout<<i<<endl;
                dfs(i, i, vals);

                vis.assign(n, false);
                sum = sum + ans;
                ans = 0;
            }
        }
        // cout<<ans<<endl;
        // cout<<sum;
        // cout<<(sum/2)+n;
        return (sum / 2) + n;
    }
};
int main(int argc, const char **argv)
{
    Solution s;
    vector<int> vals = {2, 4, 1, 2, 2, 5, 3, 4, 4};
    // vector<int> vals = {2,5,5,1,5,2,3,5,1,5};
    vector<vector<int>> edges = {{0, 1}, {2, 1}, {0, 3}, {1, 4}, {4, 5}, {3, 6}, {5, 7}, {8, 2}};
    s.numberOfGoodPaths(vals, edges);
    return 0;
}