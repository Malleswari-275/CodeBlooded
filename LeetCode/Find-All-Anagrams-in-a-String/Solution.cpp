1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4        map<char,int>win, ps;
5        for(char ch : p)ps[ch]++;
6        int k = p.size();
7        if(k > s.size()) return {};
8        for(int i = 0; i < k; i++) win[s[i]]++;
9        vector<int>vc;
10        if(win == ps) vc.push_back(0);
11        for(int i = k; i < s.size(); i++){
12            win[s[i-k]]--;
13            if(win[s[i-k]] == 0) win.erase(s[i-k]);
14            win[s[i]]++;
15            if(win == ps) vc.push_back(i-k+1);
16        }
17        return vc;
18    }
19};