#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<char, vector<char>> graph;
    unordered_map<char, bool> vis;
    int mini;
    char dfs(char vertix)
    {
        vis[vertix] = true;

        mini = min(int(vertix), mini);
        for (auto var : graph[vertix])
        {
            if (!vis[var])
            {

                dfs(var);
            }
        }
        return char(mini);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.length();
        // graph.resize(n);
        // vis.resize(n, false);
        for (int i = 0; i < n; i++)
        {
            // int n1 = static_cast<int>(s1[i]);
            // int n2 = static_cast<int>(s2[i]);
            graph[s1[i]].push_back(s2[i]);
            graph[s2[i]].push_back(s1[i]);
        }

        for (int j = 0; j < baseStr.length(); j++)
        {
            // cout<<baseStr[j];

            char ch = baseStr[j];

            if (!vis[ch])
            {
                mini = int(ch);
                char rep = dfs(ch);

                baseStr[j] = rep;
            }
            for (auto &entry : vis)
            {
                entry.second = false;
            }
        }
        
    }
};

int main(int argc, const char **argv)
{
    Solution s;
    string s1 = "parker", s2 = "morris", baseStr = "parser";
    s.smallestEquivalentString(s1, s2, baseStr);
    return 0;
}