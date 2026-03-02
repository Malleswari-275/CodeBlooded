1class Solution {
2public:
3    bool hasAlternatingBits(int n) {
4        string s = bitset<32>(n).to_string();
5        int pos = s.find('1');
6        if(pos != string::npos){
7            s = s.substr(pos);
8        }
9        else return true;
10        for(int i = 1; i < s.size(); i++) if(s[i] == s[i-1]) return false;
11        return true;
12    }
13};