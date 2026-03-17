1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int canJump = 0;
5        for(int i = 0; i < nums.size(); i++) {
6            if(i > canJump) return false;
7            canJump = max(canJump, i+nums[i]);
8        }
9        return true;
10    }
11};