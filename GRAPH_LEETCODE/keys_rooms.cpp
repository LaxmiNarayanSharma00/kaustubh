#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<bool> vis;
    int maxi=-1;
    int dfs(vector<vector<int>> &rooms, vector<bool> &vis, int room  )
    {

        vector<int>var=rooms[room];
        //  vis[room]=true;
            for (auto keys : var)
            {    

                if (!vis[keys])
                {   
                    cout<<room<<" "<<keys<<endl;
                   maxi=max(keys,maxi);
                   vis[keys]=true;
                   //    cout<<maxi<<endl;
                   
                    dfs(rooms, vis, keys);
                }
            }
        return maxi;
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {   
        int n=rooms.size();
         vis.resize(n, false);
        dfs(rooms, vis, 0);
        // cout<<maxi;
        
        for (int i = 0; i <n; i++)
        {   
            
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char **argv)
{
    Solution s;
    vector<vector<int>> rooms={{1},{2},{3},{}};
    // vector<vector<int>> rooms={{1,3},{3,0,1},{2},{0}};
    // vector<vector<int>> rooms={{1,3},{3,0,1},{2},{0}};
    cout<<s.canVisitAllRooms(rooms);
    return 0;
}