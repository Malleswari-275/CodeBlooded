1class Solution {
2public:
3    static bool cmp(vector<int>&a, vector<int>&b){
4        return a[1] < b[1];
5    }
6    int maxTwoEvents(vector<vector<int>>& events) {
7        sort(events.begin(),events.end(),cmp);
8        vector<int>maxi(events.size());
9        maxi[0] = events[0][2];
10        for(int i = 1; i < events.size(); i++){
11            maxi[i] = max(events[i][2],maxi[i-1]);
12        }
13        int ans = 0;
14        for(int i = 0; i < events.size(); i++){
15            int start = events[i][0];
16            auto it = lower_bound(events.begin(),events.end(),start,[](const vector<int>&a, int val){
17                return a[1] < val;
18            });
19            int idx = it - events.begin();
20            ans = max(ans, events[i][2]);
21            if(idx != 0)ans = max(ans,maxi[idx-1]+events[i][2]);
22        }
23        return ans;
24    }
25};