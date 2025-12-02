1class Solution {
2public:
3    bool judgeCircle(string s) {
4        int x = 0, y = 0;
5        for(int i = 0; i < s.size(); i++){
6            if(s[i] == 'U') x -= 1;
7            else if(s[i] == 'D') x+=1;
8            else if(s[i] == 'L') y += 1;
9            else y -= 1;
10        }
11        if(x == 0 && y == 0) return true;
12        return false;
13    }
14};