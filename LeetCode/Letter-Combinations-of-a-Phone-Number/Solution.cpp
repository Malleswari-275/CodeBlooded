1class Solution {
2public:
3    vector<string> combo(map<int, vector<string>>& mp, string s, int n) {
4        if (n == 0) return mp[s[0] - '0'];
5        vector<string> v = combo(mp, s, n - 1);
6        vector<string> ans;
7        vector<string> vc = mp[s[n] - '0'];
8        for (int i = 0; i < v.size(); i++) {
9            for (int j = 0; j < vc.size(); j++) {
10                ans.push_back(v[i] + vc[j]);
11            }
12        }
13        return ans;
14    }
15
16    vector<string> letterCombinations(string digits) {
17        vector<string> vc;
18        if (digits.empty()) return vc; 
19        map<int, vector<string>> mp;
20        mp[2] = {"a", "b", "c"};
21        mp[3] = {"d", "e", "f"};
22        mp[4] = {"g", "h", "i"};
23        mp[5] = {"j", "k", "l"};
24        mp[6] = {"m", "n", "o"};
25        mp[7] = {"p", "q", "r", "s"};
26        mp[8] = {"t", "u", "v"};
27        mp[9] = {"w", "x", "y", "z"};
28
29        vc = combo(mp, digits, digits.size() - 1);
30        return vc;
31    }
32};
33