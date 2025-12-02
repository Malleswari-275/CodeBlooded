1class Solution {
2public:
3    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
4        int m = mat.size();
5        int n = mat[0].size();
6        if(r*c != m*n) return mat;
7        vector<vector<int>>ans(r,vector<int>(c));
8        int k = 0, l = 0;
9        for(int i = 0; i < r; i++){
10            for(int j = 0; j < c; j++){
11                ans[i][j] = mat[k][l];
12                l++;
13                if(l >= n){
14                    l = 0;
15                    k++;
16                }
17            }
18        }
19        return ans;
20    }
21};