1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        vector<int>vc(nums.size());
5        int i = 0;
6        int k = nums.size()-1;
7        int n = nums.size();
8        for(int j = 0; j < nums.size(); j++){
9            if(nums[j] < pivot){
10                vc[i] = nums[j];
11                i++;
12            }
13            if(nums[n-j-1] > pivot){
14                vc[k] = nums[n-j-1];
15                k--;
16            }
17        }
18        for(int j = 0; j < nums.size(); j++){
19            if(nums[j] == pivot){
20                vc[i] = nums[j];
21                i++;
22            }
23        }
24        return vc;
25    }
26};