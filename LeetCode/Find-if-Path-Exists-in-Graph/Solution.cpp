1class Solution {
2public:
3    bool components(vector<vector<int>>& adj, int src, int dest, vector<bool>& visited){
4        if(!visited[src]) visited[src] = true;
5        queue<int>q;
6        q.push(src);
7        while(!q.empty()){
8            int top = q.front();
9            q.pop();
10            if(top == dest) return true;
11            for(int x : adj[top]){
12                if(!visited[x]){
13                    visited[x] = true;
14                    q.push(x);
15                }
16            }
17        }
18        return false;
19    }
20    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
21        if(source == destination) return true;
22
23        // adjacency list
24        vector<vector<int>>adj(n);
25        for(auto it : edges){
26            int u = it[0], v = it[1];
27            adj[u].push_back(v);
28            adj[v].push_back(u);
29        }
30        vector<bool>visited(n,false);
31
32        return components(adj,source,destination,visited);
33    }
34};