1class Solution {
2public:
3    int removeAlmostEqualCharacters(string word) {
4        int ans = 0;
5        for(int i = 1; i < word.size(); i++){
6            if(word[i-1] == '*') continue;
7            if((word[i] == word[i-1] || word[i] == word[i-1]-1 || word[i]==word[i-1]+1)){
8                word[i] = '*';
9                ans++;
10            }
11        }
12        return ans;
13    }
14};