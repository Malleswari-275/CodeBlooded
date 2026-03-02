1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        for(int i = 0; i < numbers.size(); i++){
5            int rem = target-numbers[i];
6            if(rem > numbers[numbers.size() - 1]) continue;
7            int idx_l = lower_bound(numbers.begin(),numbers.end(),rem) - numbers.begin();
8            if(idx_l == i){
9                int idx_u = upper_bound(numbers.begin(),numbers.end(),rem) - numbers.begin() - 1;
10                if(idx_l == idx_u) continue;
11                else{
12                    if(idx_l < idx_u) return {idx_l+1,idx_u+1};
13                    return {idx_u+1,idx_l+1};
14                }
15            }
16            if(numbers[i] + numbers[idx_l] == target){
17                if(idx_l < i) return {idx_l+1,i+1};
18                return {i+1,idx_l+1};
19            }
20        }
21        return {};
22    }
23};