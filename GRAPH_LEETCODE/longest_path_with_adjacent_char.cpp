#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> graph;
    vector<int> v;
    int result;
    int dfs(int vertix, int parent, vector<vector<int>> graph, string s)
    {
        int ans = 0;
        int max1,mx2;
        vector<int>child_ans;
        for (auto var : graph[vertix])
        {
            if (var == parent)
            {
                continue;
            }
            int child_ans1 = dfs(var, vertix, graph, s);
            if (s[var] == s[vertix])
            {
                continue;
            }
            child_ans.push_back(child_ans1);
            


            
        }
        sort(child_ans.begin(),child_ans.end(),greater<int>());
        if(child_ans.size()>=2){
            max1=child_ans[0];
            mx2=child_ans[1];
        }
        if(child_ans.size()==1){
            max1=child_ans[0];
        }
        // if (child_ans.size()==0)
        // {
        //     max1=0;
        // }
        
         result = max(result,1 + max1+mx2);
         return max(1,1+max1);
    }
    int longestPath(vector<int> &parent, string s)
    {

        int n = s.length();
        v.resize(n);
        graph.resize(n);
        for (int i = 1; i < n; i++)
        {
            graph[parent[i]].push_back(i);
            graph[i].push_back(parent[i]);
        }

        dfs(0, -1, graph, s);
        int final_ans = -1;
        for (auto nodes : v)
        {
            final_ans = max(nodes, final_ans);
        }
        return result;
    }
};

int main(int argc, const char **argv)
{

    Solution s;
    vector<int> parent = {-1, 0, 0, 1, 1, 2};
    string s = "abacbe";
    string s = "abacbe";
    s.longestPath(parent, s);

    return 0;
}
