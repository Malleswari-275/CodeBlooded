1class Solution {
2public:
3    set<int>secrets;
4    void BFS(vector<vector<pair<int,int>>>& adj, int n, int firstP){
5        vector<int>visited(n,INT_MAX);
6
7        queue<pair<int,int>>q;
8        q.push({0,0});
9        q.push({firstP,0});
10
11        visited[0] = 0;
12        visited[firstP] = 0;
13
14        secrets.insert(0);
15        secrets.insert(firstP);
16
17        while(!q.empty()){
18            auto [p,t] = q.front();
19            q.pop();
20            for(auto x : adj[p]){
21                if(t <= x.second && visited[x.first] > x.second)
22                {
23                    secrets.insert(x.first);
24                    q.push(x);
25                    visited[x.first] = x.second;
26                }
27            }
28        }
29
30    }
31    static bool cmp(vector<int>&a, vector<int>&b){
32        return a[2] < b[2];
33    }
34    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
35        vector<vector<pair<int,int>>>adj(n);
36       sort(meetings.begin(),meetings.end(),cmp);
37        for(int i = 0; i < meetings.size(); i++){
38            int u = meetings[i][0];
39            int v = meetings[i][1];
40            int t = meetings[i][2];
41            adj[u].push_back({v,t});
42            adj[v].push_back({u,t});
43        }
44
45        BFS(adj,n,firstPerson);
46        vector<int> v(secrets.begin(),secrets.end());
47        return v;
48    }
49};