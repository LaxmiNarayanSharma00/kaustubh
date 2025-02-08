#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<string, int> level;
    unordered_map<string, bool> visited;
    int find_difference(string str1, string str2)
    {
        int count = 0;
        for (int i = 0; i < 8; i++)
        {
            if (str1[i] != str2[i])
            {
                count++;
            }
        }
        return count;
    }

    int bfs(string source, string endGene, map<string, vector<string>> graph)
    {
        queue<string> q;
        q.push(source);
        // cout<<endGene<<endl;
        visited[source] = true;
        level[source]=0;
        while (!q.empty())
        {   

            string curr_v = q.front();
            // cout<<curr_v<<" ";
            q.pop();
            for (auto var : graph[curr_v])
            {   
                // cout<<var;
                if (!visited[var])
                {
                    q.push(var);
                    visited[var] = true;
                    level[var] = level[curr_v] + 1;
                    // cout<<level[var]<<endl;
                    
                    if(var==endGene){
                        // cout<<level[endGene];
                        return level[endGene];
                    }
                }
            }
        }
        
        return -1;
    }
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        map<string, vector<string>> graph;
        //   cout<<startGene;
        bank.push_back(startGene);

        for (auto parent : bank)
        {
            for (auto child : bank)
            {
                int diff_count = find_difference(parent, child);
                if (diff_count == 1)
                {
                    graph[parent].push_back(child);
                    //    cout<<parent<<" "<<child<<endl;
                }
            }
        }

        int ans= bfs(startGene, endGene, graph);
        return ans;
    }
};

int main(int argc, const char **argv)
{
    Solution s;
    string start = "AACCGGTT", end = "AAACGGTA";
    // cout<<start;
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};

    s.minMutation(start, end, bank);

    return 0;
}