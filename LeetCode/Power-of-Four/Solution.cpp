1class Solution {
2public:
3    bool isPowerOfFour(int n) {
4        if(n == 1) return true;
5        else if(n == 0) return false;
6        if(n%4 == 0) return isPowerOfFour(n/4);
7        else return false;
8    }
9};