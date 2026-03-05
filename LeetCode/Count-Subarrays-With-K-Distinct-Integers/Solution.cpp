1class Solution {
2public:
3    long long solve(vector<int>& nums, int k, int m){
4        long long maxi = 100001;
5        // if(k == 1 && m == 1) return (long long)nums.size();
6        long long extra = 0;
7        vector<long long>mp(maxi,0);
8        long long ans = 0;
9        long long i = 0, freq_cnt = 0, distincts = 0;
10        for(long long j = 0; j < nums.size(); j++){
11            if(mp[nums[j]] == 0) distincts++;
12            mp[nums[j]]++;
13            if(mp[nums[j]] == m) freq_cnt++;
14            int cnt = 1;
15            while(distincts > k){
16                
17                
18                if(mp[nums[i]] == m) freq_cnt--;
19                mp[nums[i]]--;
20                if(mp[nums[i]] == 0) distincts--;
21                i++;
22                extra = 0;
23            }
24            // if(distincts == k && freq_cnt == k) {
25            //     if(cnt >= 1)ans += cnt*(j-i);
26            //     else ans++;
27            // }
28            // if(distincts == k && freq_cnt < k) i = j;
29            // if(distincts == k && freq_cnt == k){
30                // long long temp = i;
31                while(mp[nums[i]] > m){
32                    mp[nums[i]]--;
33                    i++;
34                    extra++;
35                }
36            if(distincts == k && freq_cnt == k) ans += extra+1;
37            // }
38        }
39        return ans;
40    }
41    long long countSubarrays(vector<int>& nums, int k, int m) {
42        return solve(nums,k,m);
43    }
44};