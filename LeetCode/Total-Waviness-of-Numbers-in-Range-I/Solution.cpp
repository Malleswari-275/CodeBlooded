1class Solution {
2public:
3    int totalWaviness(int num1, int num2) {
4        int cnt = 0;
5        for(int i = num1; i <= num2; i++){
6            if(i < 100) continue;
7            string s = to_string(i);
8            for(int j = 1; j < s.size()-1; j++){
9                if((s[j] > s[j-1] && s[j] > s[j+1]) || (s[j] < s[j-1] && s[j] < s[j+1])) cnt++;
10            }
11        }
12        return cnt;
13    }
14};