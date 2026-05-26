1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        map<char,int>mp;
5        for(int i = 0; i < word.size(); i++){
6            if(word[i] >= 'A' && word[i] <= 'Z') mp[word[i]]++;
7        }
8        int cnt = 0;
9        for(int i = 0; i < word.size(); i++){
10            if(word[i] >= 'a' && word[i] <= 'z'){
11                if(mp.find(toupper(word[i])) != mp.end()){
12                    cnt++;
13                    mp.erase(toupper(word[i]));
14                }
15            }
16        }
17        return cnt;
18    }
19};