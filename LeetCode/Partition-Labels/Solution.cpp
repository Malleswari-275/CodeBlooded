1class Solution {
2public:
3    vector<int> partitionLabels(string s) {
4        map<char,int>mp;
5        for(int i = 0; i < s.size(); i++) mp[s[i]] = i;
6        vector<int>vc;
7        int j = 0;
8        int maxi = 0;
9        for(int i = 0; i < s.size(); i++){
10            maxi = max(maxi,mp[s[i]]);
11            if(i == maxi){
12                vc.push_back(i-j+1);
13                j = i+1;
14            }
15        }
16        return vc;
17    }
18};