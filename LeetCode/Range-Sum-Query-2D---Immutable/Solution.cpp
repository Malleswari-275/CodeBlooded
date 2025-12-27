1class NumMatrix {
2public:
3    vector<vector<int>>vc;
4    NumMatrix(vector<vector<int>>& matrix) {
5        vc = matrix;
6        for(int i = 0; i < vc.size(); i++){
7            for(int j = 1; j < vc[i].size(); j++) vc[i][j] += vc[i][j-1];
8        }
9        for(int j = 0; j < vc[0].size(); j++){
10            for(int i = 1; i < vc.size(); i++) vc[i][j] += vc[i-1][j];
11        }
12    }
13    
14    int sumRegion(int row1, int col1, int row2, int col2) {
15        int total = vc[row2][col2];
16        int top = 0, left = 0;
17        if(row1-1 >= 0) top = vc[row1-1][col2];
18        if(col1-1 >= 0) left = vc[row2][col1-1];
19        total = total-top-left;
20        if(row1-1 >= 0 && col1-1 >= 0) total += vc[row1-1][col1-1];
21        return total;
22    }
23};
24
25/**
26 * Your NumMatrix object will be instantiated and called as such:
27 * NumMatrix* obj = new NumMatrix(matrix);
28 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
29 */