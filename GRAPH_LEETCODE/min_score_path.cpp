#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    vector<bool> vis;
    vector<bool>vis_edges;
    int mini=INT_MAX;
    void dfs(int vertix)
    {   
        vis[vertix]=true;
        for (auto var : mp[vertix])
        {   
            int child_node = var.first;
             
            int wt = var.second;
             mini=min(mini,wt);
            //  cout<<wt<<" "<<child_node<<" "<<vertix<<endl;
            if (!vis[child_node])
            {   
                
                
               dfs(child_node); 
            }
            
            

        }
    }
    int minScore(int n, vector<vector<int>> &roads)
    {
        for (auto var : roads)
        {
            mp[var[0]].push_back({var[1], var[2]});
            mp[var[1]].push_back({var[0], var[2]});
        }
         int sizee=roads.size();
        vis.resize(n + 1, false);
        vis_edges.resize(sizee,false);
        dfs(1);
        cout<<mini<<endl;

    }
};

int main(int argc, const char **argv)
{
    Solution s;
    int n = 6;
    vector<vector<int>> roads = {{4,5,7468},{6,2,7173},{6,3,8365},{2,3,7674},{5,6,7852},{1,2,8547},{2,4,1885},{2,5,5192},{1,3,4065},{1,4,7357}};;
    s.minScore(n, roads);

    return 0;
}