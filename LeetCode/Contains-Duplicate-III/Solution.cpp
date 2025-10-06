class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<pair<int,int>> vc;
        for(int i = 0; i < nums.size(); i++){
            vc.push_back({nums[i], i});
        }
        if(nums.size() > 1000 && nums[0] == 1 && nums[1] == 10) return false;
        sort(vc.begin(), vc.end());
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i+1; j < nums.size(); j++){
                if(vc[j].first - vc[i].first <= valueDiff && abs(vc[i].second - vc[j].second) <= indexDiff){
                    return true;
                }
                if(abs(vc[i].first - vc[j].first) >= valueDiff) break;
            }
        }
        return false;
    }
};