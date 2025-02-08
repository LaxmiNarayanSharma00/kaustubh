#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> parent;
    vector<vector<int>> graph;
    vector<int> size;
    map<int, vector<int>> mp;
    void make(int vertix)
    {
        parent[vertix] = vertix;
        size[vertix] = 1;
    }
    int find_parent(int vertix)
    {
        if (parent[vertix] == vertix)
        {
            return vertix;
        }

        return parent[vertix] = find_parent(parent[vertix]);
    }

    void make_union(int a, int b)
    {
        int parent_a = find_parent(a);
        int parent_b = find_parent(b);
        if (parent_a != parent_b)
        {
            if (size[parent_a] < size[parent_b])
            {
                swap(parent_a, parent_b);
            }
        }
        parent[parent_b] = parent[parent_a];
        size[parent_a] = size[parent_a] + size[parent_b];
    }

    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        int n = vals.size();
        for (int i = 0; i < n; i++)
        {
            mp[vals[i]].push_back(i);
        }

        for (auto var : edges)
        {
            graph[var[0]].push_back(var[1]);
            graph[var[1]].push_back(var[0]);
        }
        vector<int> active_nodes;
        for (auto var : mp)
        {
            for (auto nodes : var.second)
            {
                active_nodes.push_back(nodes);
                make(nodes);
            }

            for (auto var : edges)
            {
                int node1 = var[0];
                int node2 = var[1];

                auto it1 = find(active_nodes.begin(), active_nodes.end(), node1);
                auto it2 = find(active_nodes.begin(), active_nodes.end(), node2);

                if (it1 != active_nodes.end() && it2 != active_nodes.end())
                {
                    make_union(node1, node2);
                }
            }
            
            

        }
        // for(auto var : mp)
        // {
        //     cout<<var.first;
        // }
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