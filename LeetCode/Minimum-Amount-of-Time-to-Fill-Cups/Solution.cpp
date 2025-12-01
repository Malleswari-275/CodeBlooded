1class Solution {
2public:
3    int fillCups(vector<int>& amount) {
4        int maxi = *max_element(amount.begin(),amount.end());
5        int total = accumulate(amount.begin(),amount.end(),0);
6        return max(maxi,(total+1)/2);
7    }
8};