1class Solution {
2public:
3    char findTheDifference(string s, string t) {
4        sort(s.begin(),s.end());
5        sort(t.begin(),t.end());
6
7        for(int i = 0; i < s.size(); i++){
8            if(s[i] != t[i]) return t[i];
9        }
10        return t[t.size()-1];
11    }
12};