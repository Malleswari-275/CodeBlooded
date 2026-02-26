1class Solution {
2public:
3    void binaryAddition(string &s){
4        int carry = 1;
5        for(int i = s.size()-1; i >= 0; i--){
6            if(s[i] == '1' && carry == 1){
7                s[i] = '0';
8            }
9            else{
10                if(carry == 1){
11                    s[i] = '1';
12                    carry = 0;
13                }
14            }
15            if(carry == 0) break;
16        }
17        if(carry == 1) s.insert(s.begin(),'1');
18    }
19    int numSteps(string s) {
20        int cnt = 0;
21        while(s.size() > 1){
22            if(s[s.size()-1] == '1'){
23                binaryAddition(s);
24            }
25            else s.pop_back();
26            cnt++;
27        }
28        return cnt;
29    }
30};