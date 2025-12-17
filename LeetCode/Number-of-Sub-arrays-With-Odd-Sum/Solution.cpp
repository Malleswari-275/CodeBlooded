1class Solution {
2public:
3     int mod = 1e9 + 7;
4    int numOfSubarrays(vector<int>& arr) {
5        int even = 0;
6        int odd = 0;
7        int ans = 0;
8        for(int i = 1; i < arr.size(); i++) arr[i] += arr[i-1];
9        for(int i = 0; i < arr.size(); i++){
10
11            if(arr[i]%2 == 0){
12                ans= (ans+odd)%mod;
13                even++;
14            }
15            else{
16                ans = (ans+even+1)%mod;
17                odd++;
18            }
19        }
20        return ans%mod;
21    }
22};