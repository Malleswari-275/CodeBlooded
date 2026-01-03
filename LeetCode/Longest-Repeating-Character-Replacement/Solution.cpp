1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        unordered_map<char,int>mp;
5        int ans = 0, i = 0, maxi = 0;
6        for(int j = 0; j < s.size(); j++){
7            mp[s[j]]++;
8            maxi = max(maxi,mp[s[j]]);
9            while((j-i+1)-maxi > k){
10                mp[s[i]]--;
11                i++;
12            }
13
14            ans = max(ans,j-i+1);
15        }
16        return ans;
17    }
18};