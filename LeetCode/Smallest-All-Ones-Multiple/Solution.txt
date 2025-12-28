1class Solution {
2public:
3    int minAllOneMultiple(int k) {
4        // IMPOSSIBLE CASE
5        if(k%2 == 0 || k%5 == 0) return -1;
6        int rem =0;
7        for(int i = 1; i <= 100000; i++){
8            rem = (rem*10 + 1)%k;
9            if(rem == 0) return i;
10        }
11        return -1;
12    }
13};