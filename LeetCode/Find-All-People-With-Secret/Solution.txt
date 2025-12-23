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
19            cout<<p<<" "<<t<<endl;
20            q.pop();
21            for(auto x : adj[p]){
22                if(t <= x.second && visited[x.first] > x.second)
23                {
24                    secrets.insert(x.first);
25                    q.push(x);
26                    visited[x.first] = x.second;
27                }
28            }
29        }
30
31    }
32    static bool cmp(vector<int>&a, vector<int>&b){
33        return a[2] < b[2];
34    }
35    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
36        vector<vector<pair<int,int>>>adj(n);
37       sort(meetings.begin(),meetings.end(),cmp);
38        for(int i = 0; i < meetings.size(); i++){
39            int u = meetings[i][0];
40            int v = meetings[i][1];
41            int t = meetings[i][2];
42            adj[u].push_back({v,t});
43            adj[v].push_back({u,t});
44        }
45
46        BFS(adj,n,firstPerson);
47        vector<int> v(secrets.begin(),secrets.end());
48        return v;
49    }
50};