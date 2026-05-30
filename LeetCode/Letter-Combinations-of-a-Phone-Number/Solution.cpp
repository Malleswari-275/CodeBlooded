1class Solution {
2public:
3    
4
5    vector<string>vc;
6    void backtrack(string digits, map<char,vector<char>>&mp, string st, int i){
7        if(i == digits.size()){
8            vc.push_back(st);
9            return;
10        }
11        if(i >= digits.size()) return;
12        vector<char>ch = mp[digits[i]];
13        for(int j = 0; j < ch.size(); j++){
14            st += ch[j];
15            backtrack(digits,mp,st,i+1);
16            st.pop_back();
17        }
18    }
19    vector<string> letterCombinations(string digits) {
20        map<char,vector<char>>mp;
21        mp['2'] = {'a','b','c'};
22        mp['3'] = {'d', 'e', 'f'};
23        mp['4'] = {'g', 'h', 'i'};
24        mp['5'] = {'j', 'k', 'l'};
25        mp['6'] = {'m', 'n', 'o'};
26        mp['7'] = {'p', 'q', 'r', 's'};
27        mp['8'] = {'t', 'u', 'v'};
28        mp['9'] = {'w', 'x', 'y', 'z'};
29
30        backtrack(digits,mp,"",0);
31        return vc;
32        
33    }
34};