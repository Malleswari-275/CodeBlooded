1class Solution {
2public:
3    string processStr(string s) {
4        string res = "";
5        for(int i= 0; i < s.size(); i++){
6            if(s[i] >= 'a' && s[i] <= 'z') res += s[i];
7            else if(s[i] == '*'){
8                if(!res.empty())res.pop_back();
9            }
10            else if(s[i] == '#'){
11                res += res;
12            }
13            else if(s[i] == '%') reverse(res.begin(),res.end());
14        }
15        return res;
16    }
17};