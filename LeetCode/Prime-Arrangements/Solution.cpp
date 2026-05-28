1class Solution {
2public:
3    const int mod = 1e9 + 7;
4    int numPrimeArrangements(int n) {
5        int primes = 0;
6        for(int i = 2; i <= n; i++){
7            int cnt = 0;
8            for(int j = 2; j <= sqrt(i); j++){
9                if(i%j == 0) cnt++;
10            }
11            if(cnt == 0) primes++;
12        }
13        long long pp = 1, cc = 1;
14        int rem = n-primes;
15        while(primes){
16            pp = (pp*primes)%mod;
17            primes -= 1;
18        }
19        while(rem){
20            cc = (cc*rem)%mod;
21            rem -= 1;
22        }
23        return (pp*cc)%mod;
24    }
25};