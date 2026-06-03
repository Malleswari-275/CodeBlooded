1class Solution {
2public:
3    int triangularSum(vector<int>& nums) {
4        int n = nums.size();
5        vector<vector<int>>vc(n);
6        vc[0] = (nums);
7        for(int i = 1; i < n; i++){
8            vector<int>curr;
9            for(int j = 0; j <= n-i-1; j++){
10                curr.push_back((vc[i-1][j] + vc[i-1][j+1])%10);
11            }
12            vc[i] = curr;
13        }
14        return vc[n-1][0];
15    }
16};