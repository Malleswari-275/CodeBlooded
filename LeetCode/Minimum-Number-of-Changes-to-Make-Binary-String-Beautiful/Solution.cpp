1class Solution {
2public:
3    int minChanges(string s) {
4        int cnt = 0;
5        for(int i = 0; i < s.size(); i+=2){
6            if(s[i] != s[i+1]) cnt++;
7        }
8        return cnt;
9    }
10};