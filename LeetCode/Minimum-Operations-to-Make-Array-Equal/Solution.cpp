1class Solution {
2public:
3    int minOperations(int n) {
4        int ans = 0;
5        for(int i = 0; i < n/2; i++){
6            ans += n - (2*i + 1);
7        }
8        return ans;
9    }
10};