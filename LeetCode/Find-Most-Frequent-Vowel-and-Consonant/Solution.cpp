class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        for(int i = 0; i < s.length(); i++) mp[s[i]]++;
        int vo = 0, co = 0;
        for(auto it : mp){
            if(it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u') vo = max(vo,it.second);
            else{
                co = max(co,it.second);
            }
        }
        return vo+co;
    }
};