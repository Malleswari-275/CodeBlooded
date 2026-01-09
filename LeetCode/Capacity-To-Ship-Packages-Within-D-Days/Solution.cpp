1class Solution {
2public:
3    int shipWithinDays(vector<int>& weights, int days) {
4        int sum = accumulate(weights.begin(),weights.end(),0);
5        int low = *max_element(weights.begin(), weights.end()), high = sum;
6        int mid;
7        while(low <= high){
8            int cnt = 1;
9            mid = low + (high-low)/2;
10            int curr = 0;
11            for(int i = 0; i < weights.size(); i++){
12                if(curr+weights[i] > mid){
13                    cnt++;
14                    curr = weights[i];
15                }
16                else curr += weights[i];
17            }
18            if(cnt <= days){
19                high = mid-1;
20            }
21            else low = mid+1;
22        }
23        return low;
24    }
25};