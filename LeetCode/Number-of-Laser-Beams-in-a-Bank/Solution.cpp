class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        string s = bank[0];
        int ones = count(s.begin(),s.end(),'1');
        for(int i = 1; i < bank.size(); i++){
            int curr = count(bank[i].begin(),bank[i].end(),'1');
            if(curr != 0 && ones != 0){
                ans += curr*ones;
                ones = curr;
            }
            if(ones == 0) ones = curr;
        }
        return ans;
    }
};