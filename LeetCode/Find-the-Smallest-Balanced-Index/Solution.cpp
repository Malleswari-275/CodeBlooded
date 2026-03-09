1class Solution {
2public:
3    int smallestBalancedIndex(vector<int>& nums) {
4        vector<long long>sums;
5        vector<long long>products;
6        long long sum = 0;
7        for(int i = 0; i < nums.size(); i++){
8            sum += nums[i];
9            sums.push_back(sum);
10            
11        }
12        long long product = 1;
13        long long c = 1e15;
14        products.push_back(nums[nums.size()-1]);
15        for(int i = nums.size()-2; i >= 0; i--){
16            if(products.back() > c/nums[i]){
17                products.push_back(1e15);
18            }
19            else{
20                product = products.back()*nums[i];
21                products.push_back(product);
22            }
23        }
24        reverse(products.begin(),products.end());
25        for(int i = 0; i < nums.size(); i++){
26            long long left = sums[i]-nums[i];
27            long long right = i+1 < nums.size() ? products[i+1] : 1;
28            if(left == right) return i;
29        }
30        return -1;
31    }
32};