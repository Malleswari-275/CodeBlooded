1class Solution {
2public:
3    vector<string> findRepeatedDnaSequences(string s) {
4        unordered_map<string,int>mp;
5        string st = "";
6        int j = 0;
7        if(s.size() < 10) return {};
8        for(int i = 0; i < 10; i++) st += s[i];
9        mp[st]++;
10        for(int i = 10; i < s.size(); i++){
11            st.erase(st.begin());
12            st += s[i];
13            mp[st]++;
14        }
15        vector<string>vc;
16        for(auto it: mp){
17            if(it.second > 1) vc.push_back(it.first);
18        }
19        return vc;
20    }
21};