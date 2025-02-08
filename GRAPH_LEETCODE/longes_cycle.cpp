#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> inrec;
    vector<bool> vis;
    vector<int> counter;
    vector<vector<int>> graph;
    int countt;

    bool isCycleDFS(int vertix)
    {
        vis[vertix] = true;
        inrec[vertix] = true;

        for (auto child : graph[vertix])
        {
            // if not visited, then we check for cycle in DFS
            if (vis[child] == false && isCycleDFS(child))
                return true;
            else if (inrec[child] == true)
                return true;
        }

        inrec[vertix] = false;
        return false;
    }

    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();

        inrec.resize(n, false);
        counter.resize(n, 1);
        vis.resize(n, false);
        graph.resize(n);
        for (int i = 0; i < n; i++)
        {
            graph[i].push_back(edges[i]);
        }

        // cout<<n;
        // dfs(0, -1, edges);

        countt = 0;
        // dfs(0, -1, edges);
        // cout<<countt<<endl;

        // for(auto var : inrec)
        // {
        //     cout<<var<<endl;
        // }
        int mini = -1;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, edges);
                mini = max(mini, countt);
                countt = 0;
            }
        }
        cout << mini << endl;
        return mini == 0 ? -1 : mini;
    }
};

int main(int argc, const char **argv)
{
    Solution s;
    // vector<int> edges = {3,4,0,2,-1,2};
    // vector<int> edges = {1,0};
    vector<int> edges = {3, 3, 4, 2, 3};
    s.longestCycle(edges);

    return 0;
}

// Function to detect cycle in a directed graph.
// bool isCyclic(int V, vector<int> adj[]) {
//     vector<bool> visited(V, false);
//     vector<bool> inRecursion(V, false);

//     for(int i = 0; i<V; i++) {
//         if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
//             return true;
//     }

//     return false;
// }