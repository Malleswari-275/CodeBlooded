1class Solution {
2public:
3    vector<vector<int>> generate(int numRows) {
4        vector<vector<int>>vc(numRows);
5        vc[0].push_back(1);
6        for(int i = 1; i < numRows; i++){
7            vector<int>curr;
8            for(int j = 0; j <= i; j++){
9                if(i == j || j == 0) curr.push_back(1);
10                else{
11                    int val = vc[i-1][j] + vc[i-1][j-1];
12                    curr.push_back(val);
13                }
14            }
15            vc[i] = curr;
16        }
17        return vc;
18    }
19};