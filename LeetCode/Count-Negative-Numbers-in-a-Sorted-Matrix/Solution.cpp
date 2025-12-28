1class Solution {
2public:
3    int countNegatives(vector<vector<int>>& grid) {
4        int cnt = 0;
5        for(int i = 0; i < grid.size(); i++){
6            for(int j = 0; j < grid[i].size(); j++){
7                if(grid[i][j] < 0) cnt++;
8            }
9        }
10        return cnt;
11    }
12};