1class Solution {
2public:
3    int minMutation(string s, string e, vector<string>& bank) {
4        map<string,int>mp;
5        for(int i = 0; i < bank.size(); i++) mp[bank[i]]++;
6        queue<pair<string,int>>q;
7        q.push({s,0});
8        vector<int>chs = {'C','G', 'T', 'A'};
9        while(!q.empty()){
10            auto [st,op] = q.front();
11            q.pop();
12            if(st == e) return op;
13            for(auto ch : chs){
14
15                for(int i = 0; i < 8; i++){
16                    char old = st[i];
17                    st[i] = ch;
18                    if(mp.find(st) != mp.end()){
19                        mp[st]--;
20                        if(mp[st] == 0) mp.erase(st);
21                        q.push({st,op+1});
22
23                    }
24                    st[i] = old;
25                }
26            }
27
28
29        }
30        return -1;
31    }
32};