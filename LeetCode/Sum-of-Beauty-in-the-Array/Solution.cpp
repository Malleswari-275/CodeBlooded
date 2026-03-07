1class Solution {
2public:
3    int sumOfBeauties(vector<int>& nums) {
4        int beauty = 0;
5        multiset<int>left,right;
6        left.insert(nums[0]);
7        for(int i = 2; i < nums.size(); i++){
8            right.insert(nums[i]);
9        }
10
11        for(int i = 1; i < nums.size()-1; i++){
12            if(*left.rbegin() < nums[i] && nums[i] < *right.begin()) beauty += 2;
13            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) beauty += 1;
14            else beauty += 0;
15            left.insert(nums[i]);
16            auto it = right.find(nums[i+1]);
17            right.erase(it);
18        }
19        return beauty;
20    }
21};