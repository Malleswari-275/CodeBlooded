class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>vc;
        for(int i = 1; i <= n/2; i++){
            vc.push_back(i);
            vc.push_back(-i);
        }
        if(n%2 == 1) vc.push_back(0);
        return vc;
    }
};