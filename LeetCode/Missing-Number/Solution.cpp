1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        int len = nums.size();
5        int sumOf_N_Natural_Nums = len*(len+1)/2;
6        int sum_of_nums_inArray = 0;
7        for(int num:nums){
8            sum_of_nums_inArray += num;
9        }
10        int res = sumOf_N_Natural_Nums - sum_of_nums_inArray;
11        return res;
12    }
13};