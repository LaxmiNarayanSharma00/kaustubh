#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    
    vector<vector<int>> graph;
    vector<bool> vis;
    void dfs(int source, int destination)
    {
        vis[source] = true;
        for (auto var : graph[source])
        {
            if (!vis[var])
            {
                dfs(var, destination);
            }
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        int size = edges.size();
        graph.resize(size);
        for (auto var : edges)
        {
            graph[var[0]].push_back(var[1]);
            graph[var[1]].push_back(var[0]);
        }
        dfs(source, destination);
        if (vis[destination])
        {
            return true;
        }
        else
        {
            false;
        }
    }
};