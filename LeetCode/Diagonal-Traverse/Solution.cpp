1class Solution {
2public:
3    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
4        vector<vector<int>> vc;
5
6        for(int i = 0; i < mat.size(); i++){
7            for(int j = 0; j < mat[i].size(); j++)
8                vc.push_back({i+j, i, mat[i][j]});
9        }
10
11        sort(vc.begin(), vc.end(), [](auto &a, auto &b){
12            if(a[0] != b[0]) return a[0] < b[0]; 
13            return a[1] < b[1];               
14        });
15
16        int start = 0;
17        for(int i = 1; i <= vc.size(); i++){
18            if(i == vc.size() || vc[i][0] != vc[i-1][0]){
19                if(vc[start][0] % 2 == 0){
20                    reverse(vc.begin()+start, vc.begin()+i);
21                }
22                start = i;
23            }
24        }
25
26        vector<int> ans;
27        for(auto &v : vc) ans.push_back(v[2]);
28        return ans;
29    }
30};
31