1class Solution {
2public:
3    int findPoisonedDuration(vector<int>& timeseries, int duration) {
4        int ans = 0;
5        long long decrease = 0;
6        for(int i = 1; i < timeseries.size(); i++){
7            if(timeseries[i]-timeseries[i-1] < duration) decrease += duration - (timeseries[i]-timeseries[i-1]);
8        }
9        ans = timeseries.size() * duration - decrease;
10        return ans;
11    }
12};