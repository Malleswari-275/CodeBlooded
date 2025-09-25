class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int>v1 = nums1;
        vector<int>v2 = nums2;
        if(v1 == v2) return 0;
        vector<vector<int>>visited;
        queue<pair<vector<int>,int>>bfs;
        bfs.push({v1,0});
        visited.push_back(v1);

        while(!bfs.empty()){
            auto [vc,steps] = bfs.front();
            bfs.pop();

            // try all subarrays
            for(int l = 0; l < n; l++){
                for(int r = l; r < n; r++){
                    vector<int>subarray(vc.begin()+l, vc.begin()+r+1);
                    vector<int>remaining;
                    remaining.insert(remaining.end(),vc.begin(),vc.begin()+l);
                    remaining.insert(remaining.end(),vc.begin()+r+1,vc.end());

                    // try all the positions for the subarray 
                    for(int i = 0; i < remaining.size(); i++){
                        vector<int>merge = remaining;
                        merge.insert(merge.begin()+i, subarray.begin(),subarray.end());

                        if(merge == v2) return steps+1;
                        if(count(visited.begin(),visited.end(),merge) == 0){
                            visited.push_back(merge);
                            bfs.push({merge,steps+1});
                        }
                    }
                }
            }
        }
        return 0;
    }
};