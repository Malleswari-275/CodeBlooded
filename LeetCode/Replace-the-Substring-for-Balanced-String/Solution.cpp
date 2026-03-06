1class Solution {
2public:
3    int balancedString(string s) {
4        int n = s.size();
5        int m = n / 4;
6
7        unordered_map<char,int> mp;
8        for(char c : s) mp[c]++;
9
10        string p = "";
11        for(auto it : mp){
12            if(it.second > m){
13                for(int i = 0; i < it.second - m; i++)
14                    p += it.first;
15            }
16        }
17
18        if(p.size() == 0) return 0;
19
20        unordered_map<char,int> pv, freq;
21        for(char c : p) pv[c]++;
22        int cnt = 0;
23        int mini = INT_MAX;
24        int j = 0;
25        for(int i = 0; i < n; i++){
26            freq[s[i]]++;
27            if(pv.count(s[i]) && freq[s[i]] <= pv[s[i]]) cnt++;
28            while(cnt == p.size()){
29                mini = min(mini, i - j + 1);
30                freq[s[j]]--;
31                if(pv.count(s[j]) && freq[s[j]] < pv[s[j]])
32                    cnt--;
33                j++;
34            }
35        }
36        return mini;
37    }
38};