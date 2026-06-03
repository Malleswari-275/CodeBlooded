1class Solution {
2public:
3
4    int fun(vector<int>& v1, vector<int>& d1, vector<int>& v2, vector<int>& d2){
5        int mini = INT_MAX;
6        for(int i = 0; i < v1.size(); i++) mini = min(mini,v1[i]+d1[i]);
7        int ans = INT_MAX;
8        for(int i = 0; i < v2.size(); i++){
9            int maxi = max(mini,v2[i]);
10            ans = min(ans,maxi+d2[i]);
11        }
12        return ans;
13    }
14    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
15        int a1 = fun(landStartTime,landDuration,waterStartTime,waterDuration);
16        int a2 = fun(waterStartTime,waterDuration,landStartTime,landDuration);
17        return min(a1,a2);
18    }
19};