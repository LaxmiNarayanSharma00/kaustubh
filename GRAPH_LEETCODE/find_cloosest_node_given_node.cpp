#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> vis;
    vector<int> level;
    int bfs(int vertix, vector<int> &edges)
    {
        queue<int> q;
        q.push(vertix);

        vis[vertix] = true;
        level[vertix] = 0;
        while (!q.empty())
        {
            int top = q.front();
           
            q.pop();
            if (edges[top] != -1 && !vis[edges[top]])
            {
                 cout<<top<<" "<<edges[top]<<endl;
                vis[edges[top]] = true;
                level[edges[top]] = level[top] + 1;
                q.push(edges[top]);
            }
        }
    }
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vis.resize(n, false);
        level.resize(n, INT_MAX);
        bfs(node1, edges);
        // cout<<level[0]<<" "<<level[1]<<" "<<level[2]<<" "<<level[3]<<endl;
        vector<int> d_n1 = level;
        fill(vis.begin(),vis.end(),false);
        fill(level.begin(),level.end(),INT_MAX);
        bfs(node2, edges);
        // cout<<level[0]<<" "<<level[1]<<" "<<level[2]<<" "<<level[3]<<endl;

        vector<int> d_n2 = level;
        int mini=INT_MAX;
        int index=-1;
        for (int i = 0; i < n; i++)
        {
            if(max(d_n1[i], d_n2[i])<mini&& max(d_n1[i], d_n2[i])!=INT_MAX)
            {
               index=i;
               mini=max(d_n1[i],d_n2[i]);
            }
        }
        // cout<<index<<endl;
        return index;
    }
};

int main(int argc, const char **argv)
{
   Solution s;
   vector<int> edges={2,2,3,-1};
   int nod1=0;
   int nod2=1;
   s.closestMeetingNode(edges,nod1,nod2);
    return 0;
}