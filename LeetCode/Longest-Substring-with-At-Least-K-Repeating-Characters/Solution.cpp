1class Solution {
2public:
3    int longestSubstring(string s, int k) {
4        vector<int>total(26,0);
5        for(int i = 0; i < s.size(); i++) {
6            total[s[i] - 'a']++;
7        }
8
9        for(int i = 0; i < s.size(); i++){
10            if(total[s[i]-'a'] < k){
11                int left = longestSubstring(s.substr(0,i),k);
12                int right = longestSubstring(s.substr(i+1,s.size()),k);
13                return max(left,right);
14            }
15        }
16        return s.size();
17
18    }
19};