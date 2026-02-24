1class Solution {
2public:
3    string lastNonEmptyString(string s) {
4        unordered_map<char,int>mp;
5        for(auto it : s) mp[it]++;
6        int maxi = 0;
7        for(auto it : mp) maxi = max(maxi,it.second);
8        string st = "";
9        map<char,int>ans;
10        for(int i = s.size()-1; i >= 0; i--){
11            if(mp[s[i]] == maxi){
12                if(ans.find(s[i]) == ans.end()){
13                    ans[s[i]]++;
14                    st += s[i];
15                }
16            }
17        }
18        reverse(st.begin(),st.end());
19        return st;
20    }
21};