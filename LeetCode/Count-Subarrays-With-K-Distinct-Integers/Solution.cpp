1class Solution {
2public:
3    long long solve(vector<int>& nums, int k, int m){
4        long long maxi = 100001;
5        // if(k == 1 && m == 1) return (long long)nums.size();
6        long long cnt = 0;
7        vector<long long>mp(maxi,0);
8        long long ans = 0;
9        long long i = 0, freq_cnt = 0, distincts = 0;
10        for(long long j = 0; j < nums.size(); j++){
11            if(mp[nums[j]] == 0) distincts++;
12            mp[nums[j]]++;
13            if(mp[nums[j]] == m) freq_cnt++;
14            while(distincts > k){
15                
16                if(mp[nums[i]] == m) freq_cnt--;
17                mp[nums[i]]--;
18                if(mp[nums[i]] == 0) distincts--;
19                i++;
20                cnt = 0;
21            }
22            // if(distincts == k && freq_cnt == k) {
23            //     if(cnt >= 1)ans += cnt*(j-i);
24            //     else ans++;
25            // }
26            // if(distincts == k && freq_cnt < k) i = j;
27            // if(distincts == k && freq_cnt == k){
28                // long long temp = i;
29                while(mp[nums[i]] > m){
30                    mp[nums[i]]--;
31                    i++;
32                    cnt++;
33                }
34            if(distincts == k && freq_cnt == k) ans += cnt+1;
35            // }
36        }
37        return ans;
38    }
39    long long countSubarrays(vector<int>& nums, int k, int m) {
40        return solve(nums,k,m);
41    }
42};