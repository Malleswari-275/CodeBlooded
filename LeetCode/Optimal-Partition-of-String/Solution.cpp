1class Solution {
2public:
3    int partitionString(string s) {
4        vector<int>freq(26,0);
5        int cnt = 0;
6        // start = 0;
7        for(int i = 0; i < s.size(); i++){
8            freq[s[i]-'a']++;
9            if(freq[s[i]-'a'] > 1){
10                cnt++;
11                fill(freq.begin(),freq.end(),0);
12                freq[s[i]-'a']++;
13            }
14            
15        }
16        if(freq[s[s.size()-1] - 'a'] <= 1) cnt++;
17        return cnt;
18    }
19};