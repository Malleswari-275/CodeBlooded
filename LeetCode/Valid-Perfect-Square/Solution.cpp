1class Solution {
2public:
3    bool isPerfectSquare(int num) {
4        for(long long i = 1; i*i <= num; i++){
5            if(i*i == num){
6                return true;
7            }
8        }
9        return false;
10    }
11};