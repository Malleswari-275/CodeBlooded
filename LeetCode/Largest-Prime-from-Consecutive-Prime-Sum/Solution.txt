1class Solution {
2public:
3    // bool Prime(long long num){
4    //     for(long long i = 2; i*i <= num; i++) if(num%i == 0) return false;
5    //     return true;
6    // }
7   
8    int largestPrime(int n) {
9        vector<long long>vc;
10        vector<bool>primes(n+1,true);
11        primes[0] = false;
12        primes[1] = false;
13        for(int i = 2; i*i <= n; i++){
14            if(primes[i]){
15                for(int j = i*i; j <= n; j+=i) primes[j] = false;
16            }
17        }
18        
19        for(int i = 2; i <= n; i++){
20            if(primes[i]) vc.push_back(i);
21        }
22        for(int i = 1; i < vc.size(); i++) vc[i] += vc[i-1];
23
24        for(int i = vc.size()-1; i >= 0; i--){
25            if(vc[i] <= n){
26                if(primes[vc[i]]) return vc[i];
27            }
28        }
29        // for(int i = n; i >= 2; i--){
30        //     int num = i;
31        //     if(Prime(num)){
32        //         auto low = lower_bound(vc.begin(),vc.end(),num);
33        //         if(low != vc.end()) if(*low == num) return num;
34        //     }
35        // }
36        return 0;
37    }
38    
39};