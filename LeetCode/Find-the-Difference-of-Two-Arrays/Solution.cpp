1class Solution {
2public:
3    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
4        set<int>a,b;
5        for(int i = 0; i < nums1.size(); i++){
6            if(find(nums2.begin(),nums2.end(),nums1[i]) == nums2.end()) a.insert(nums1[i]);
7        }
8        for(int i = 0; i < nums2.size(); i++){
9            if(find(nums1.begin(),nums1.end(),nums2[i]) == nums1.end()) b.insert(nums2[i]);
10        }
11        vector<int>v1(a.begin(),a.end());
12        vector<int>v2(b.begin(),b.end());
13        return {v1,v2};
14    }
15};