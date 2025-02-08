#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> graph_undir;
    vector<vector<int>> graph_org;
    vector<bool> vis;
    vector<int> level;
    void bfs()
    {
        queue<int> q;
        q.push(0);
        
        level[0] = 0;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            // cout<<top;
            vis[top] = true;
            for (auto var : graph_undir[top])
            {
                if (!vis[var])
                {
                    
                    level[var] = level[top] + 1;
                    q.push(var);
                }
            }
        }
    }
    int minReorder(int n, vector<vector<int>> &connections)
    {
        level.resize(n);
        vis.resize(n, false);
        graph_org.resize(n);
        graph_undir.resize(n);
        // cout<<n;
        for (auto var : connections)
        {
            graph_undir[var[0]].push_back(var[1]);
            graph_undir[var[1]].push_back(var[0]);
        }
        for (auto var : connections)
        {
            graph_org[var[0]].push_back(var[1]);
        }
        int count=0;
        bfs();
        for (int i = 0; i < n; i++)
        {  
            // cout<<level[i]<<endl;
            for (auto var : graph_org[i])
            {
                    if(level[var]>level[i]){
                        count++;
                    }
            }
        }
       
    //    cout<<count;
        
        return  count;
    }
};

int main(int argc, const char **argv)
{
    Solution s;
    int n = 6;
    vector<vector<int>> conn = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    // cout<<n;
    s.minReorder(n, conn);

    return 0;
}