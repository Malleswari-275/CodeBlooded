1class Solution {
2public:
3    int ans = 0;
4    bitset<30>cl,d1,d2;
5    bool valid(vector<vector<bool>>&vc, int n, int row, int col){
6        if(!cl[col] && !d1[row+col] && !d2[row-col+n-1]) return true;
7        return false;
8    }
9    void NQueens(vector<vector<bool>>&vc, int n, int row){
10        if(row == n){
11            ans++;
12            return;
13        }
14        for(int col = 0; col < n; col++){
15            if(valid(vc,n,row,col)){
16                vc[row][col] = true;
17                cl[col] = d1[row+col] = d2[row-col+n-1] = 1;
18                NQueens(vc,n,row+1);
19                vc[row][col] = false;
20                cl[col] = d1[row+col] = d2[row-col+n-1] = 0;
21            }
22        }
23    }
24    int totalNQueens(int n) {
25        vector<vector<bool>>vc(n,vector<bool>(n,false));
26        NQueens(vc,n,0);
27        return ans;
28    }
29};