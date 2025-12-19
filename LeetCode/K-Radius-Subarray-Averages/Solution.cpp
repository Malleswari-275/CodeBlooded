1class Solution {
2public:
3    vector<int> getAverages(vector<int>& nums, int k) {
4        vector<int>vc(nums.size(),-1);
5        if(nums.size() < (2*k + 1)) return vc;
6        if(k == 0) return nums;
7        long long sum = 0;
8        for(int i = 0; i < (2*k+1); i++) sum += nums[i];
9        vc[k] = sum/(2*k + 1);
10        int n = nums.size();
11        for(int i = k+1; i < n-k; i++){
12            sum -= nums[i-k-1];
13            sum += nums[k+i];
14            vc[i] = sum/(2*k + 1);
15        }
16        return vc;
17    }
18};