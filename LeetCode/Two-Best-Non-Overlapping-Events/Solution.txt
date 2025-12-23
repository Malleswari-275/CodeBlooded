1class Solution {
2public:
3    static bool cmp(vector<int>&a, vector<int>&b){
4        // if(a[1] != b[1]) 
5        return a[1] < b[1];
6        // return a[0] < b[0];
7    }
8    int maxTwoEvents(vector<vector<int>>& events) {
9        sort(events.begin(),events.end(),cmp);
10        vector<int>maxi(events.size());
11        maxi[0] = events[0][2];
12        for(int i = 1; i < events.size(); i++){
13            maxi[i] = max(events[i][2],maxi[i-1]);
14        }
15        int ans = 0;
16        for(int i = 0; i < events.size(); i++){
17            int start = events[i][0];
18            auto it = lower_bound(events.begin(),events.end(),start,[](const vector<int>&a, int val){
19                return a[1] < val;
20            });
21            int idx = it - events.begin();
22            cout<<idx;
23            ans = max(ans, events[i][2]);
24            if(idx != 0)ans = max(ans,maxi[idx-1]+events[i][2]);
25        }
26        return ans;
27    }
28};