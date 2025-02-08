#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    vector<bool> vis;
    int mini_cost = INT_MAX;


    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vis.resize(n, false);
        for (auto var : flights)
        {
            mp[var[0]].push_back({var[1], var[2]});
        }

        dfs(src, dst, k, 0, 0);
        
        return mini_cost == INT_MAX ? -1 : mini_cost;
    }
};

int main(int argc, const char **argv)
{
    Solution s;
    int n = 4, src = 0, des = 3, k = 1;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {1, 3, 600}, {2, 3, 200}};

    int result = s.findCheapestPrice(n, flights, src, des, k);
    cout << "The minimum cost is: " << result << endl;

    return 0;
}
