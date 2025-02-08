#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> graph;
    vector<int> parent;
    vector<bool> vis;
    vector<int> level;
    vector<int> no_of_nodes;
    int bfs(int source, int n)
    {
        queue<int> q;
        q.push(source);
        vis[source] = true;
        level[source] = 0;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            for (auto var : graph[top])
            {
                if (!vis[var])
                {
                    level[var] = level[top] + 1;
                    q.push(var);
                    vis[var] = true;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            // cout<<i<<level[i]<<endl;
            sum = sum + level[i];
        }
        return sum;
    }
    int DFS(int source, int n)
    {
        vis[source] = true;

        // cout<<source;
        for (auto var : graph[source])
        {
            if (!vis[var])
            {
                parent[var] = source;

                int count = DFS(var, n);

                no_of_nodes[source] = count + no_of_nodes[source];
            }
        }
        // cout << source << " " << no_of_nodes[source] << " " << parent[source] << endl;
        return no_of_nodes[source];
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        // cout << n;
        //    cout<< edges[0][0];
        graph.resize(n);
        parent.resize(n);
        vis.resize(n, false);
        level.resize(n);
        no_of_nodes.resize(n, 1);
        for (auto var : edges)
        {
            graph[var[0]].push_back(var[1]);
            graph[var[1]].push_back(var[0]);
            // cout<<var[0];
        }
        vector<int> ans(n);
        ans[0] = bfs(0, n);
        fill(vis.begin(), vis.end(), false);
        // cout<<vis[0];
        parent[0] = -1;
        DFS(0, n);
        queue<int> a;
        vector<bool> visii(n, false);
        visii[0] = true;
         a.push(0);
        while (!a.empty())
        {  
            int top =a.front();
           a.pop();
            
            for (auto var : graph[top])
            {
                if (!visii[var])
                {
                    ans[var] = ans[top] - 2 * no_of_nodes[var]+n;
                    // cout << ans[var] <<" "<<var<< endl;
                    visii[var] = true;
                    a.push(var);
                }
            }
        }

        return ans;
    }
};
int main(int argc, const char **argv)
{
    Solution s;

    vector<vector<int>> edges = {{2, 1}, {0, 2}};
    // vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    // cout<<edges[0][0];
    s.sumOfDistancesInTree(3, edges);
    return 0;
}