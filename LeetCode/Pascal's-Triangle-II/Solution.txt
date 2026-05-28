1class Solution {
2public:
3    vector<int> getRow(int rowIndex) {
4        vector<vector<int>>vc(rowIndex+1);
5        vc[0].push_back(1);
6        for(int i = 1; i <= rowIndex; i++){
7            vector<int>curr;
8            for(int j = 0; j <= i; j++){
9                if(i == j || j  == 0) curr.push_back(1);
10                else{
11                    int val = vc[i-1][j] + vc[i-1][j-1];
12                    curr.push_back(val);
13                }
14            }
15            vc[i] = curr;
16        }
17        return vc[rowIndex];
18    }
19};