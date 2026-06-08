1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        vector<int>vc(nums.size());
5        int i = 0;
6        for(int j = 0; j < nums.size(); j++){
7            if(nums[j] < pivot){
8                vc[i] = nums[j];
9                i++;
10            }
11        }
12        for(int j = 0; j < nums.size(); j++){
13            if(nums[j] == pivot){
14                vc[i] = nums[j];
15                i++;
16            }
17        }
18        for(int j = 0; j < nums.size(); j++){
19            if(nums[j] > pivot){
20                vc[i] = nums[j];
21                i++;
22            }
23        }
24        return vc;
25    }
26};