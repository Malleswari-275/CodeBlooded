1class Solution {
2public:
3    long long countVowels(string word) {
4        long long ans = 0;
5        long long n = word.size();
6        for(long long i = 0; i < n; i++){
7            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')ans += (i+1)*(n-i);
8        }
9        return ans;
10    }
11};