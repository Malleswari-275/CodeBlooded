1class Solution {
2public:
3    bool vowels(char ch){
4        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
5    }
6    int maxVowels(string s, int k) {
7        int curr = 0, maxi = 0;
8        for(int i = 0; i < k; i++){
9            if(vowels(s[i])) curr++;
10        }
11        maxi = max(maxi,curr);
12        for(int i = k; i < s.size(); i++){
13            if(vowels(s[i-k])) curr--;
14            if(vowels(s[i])) curr++;
15            maxi = max(maxi,curr);
16        }
17        return maxi;
18    }
19};