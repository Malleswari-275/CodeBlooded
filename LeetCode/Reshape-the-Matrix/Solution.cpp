1class Solution {
2public:
3    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
4        int m = mat.size();
5        int n = mat[0].size();
6        if(r*c != m*n) return mat;
7        vector<int>vc;
8        for(int i = 0; i < m; i++){
9            for(int j = 0; j < n; j++) {
10                vc.push_back(mat[i][j]);
11            }
12        }
13        vector<vector<int>>ans(r,vector<int>(c));
14        int k = 0;
15        for(int i = 0; i < r; i++){
16            for(int j = 0; j < c; j++){
17                ans[i][j] = vc[k];
18                k++;
19            }
20        }
21        return ans;
22    }
23};