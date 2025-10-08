class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);             
        unordered_map<int,int> lastRain;  
        vector<int> zeroDays;             

        for(int i = 0; i < n; i++){
            if(rains[i] == 0){
                zeroDays.push_back(i);    
            } else {
                ans[i] = -1;              
                if(lastRain.count(rains[i])) {
                    auto it = lower_bound(zeroDays.begin(), zeroDays.end(), lastRain[rains[i]] + 1);
                    if(it == zeroDays.end()) return {}; 
                    ans[*it] = rains[i];              
                    zeroDays.erase(it);              
                }
                lastRain[rains[i]] = i;            
            }
        }
        return ans;
    }
};