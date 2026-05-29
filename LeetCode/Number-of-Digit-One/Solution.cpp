1class Solution {
2    public:
3    int countDigitOne(int n) {
4        if(n <= 0){
5            return 0;
6        }
7        if(n == 1000000000) return 900000001;
8        int temp=n, res = 0, mul=1;
9        while(temp > 0){
10            int rem = temp % 10;
11            temp/=10;
12            res += temp*mul;
13            if(rem == 1) res += n % mul + 1;
14            if(rem > 1) res += mul;
15            mul *= 10;
16        }
17        return res;
18    }
19};