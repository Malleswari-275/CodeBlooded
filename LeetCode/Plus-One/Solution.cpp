1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4        reverse(digits.begin(),digits.end());
5        int carry = 1;
6        for(int i = 0; i < digits.size(); i++){
7            int sum = carry + digits[i];
8            digits[i] = sum%10;
9            carry = sum/10;
10        }
11        if(carry != 0) digits.push_back(carry);
12        reverse(digits.begin(),digits.end());
13        return digits;
14    }
15};