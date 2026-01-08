1class Solution {
2public:
3    vector<int> singleNumber(vector<int>& nums) {
4        long long ans = 0;
5        for(int i = 0; i < nums.size(); i++) ans = ans^nums[i];
6        int pos = 0;
7        for(int i = 0; i <= 64; i++){
8            if((ans&(1ll<<i)) > 0){
9                pos = i;
10                break;
11            }
12        }
13        cout<<pos;
14        int left = 0, right = 0;
15        for(int i = 0; i < nums.size(); i++){
16            if(nums[i]&(1ll<<pos)){
17                cout << nums[i] << endl;
18                left = left^nums[i];
19            }
20            else right = right^nums[i];
21        }
22        return {left,right};
23    }
24};