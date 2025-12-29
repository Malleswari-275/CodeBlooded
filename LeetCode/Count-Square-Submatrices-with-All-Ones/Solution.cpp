1class Solution {
2public:
3    int countSquares(vector<vector<int>>& matrix) {
4        vector<vector<int>>vc = matrix;
5        // row wise prefix;
6        for(int i = 0; i < matrix.size(); i++){
7            for(int j = 1; j < matrix[i].size(); j++) vc[i][j] += vc[i][j-1];
8        }
9        // coulumn wise prefix
10        for(int j = 0; j < matrix[0].size(); j++){
11            for(int i = 1; i < matrix.size(); i++) vc[i][j] +=vc[i-1][j];
12        }
13        int ans = 0;
14        for(int i = 0; i < matrix.size(); i++){
15            for(int j = 0; j < matrix[i].size(); j++){
16                // square submatrix
17                int k = i, l = j;
18                while(k < matrix.size() && l < matrix[i].size()){
19                    int left = 0; int top = 0; int diagonal = 0;
20                    if(j-1 >= 0) left = vc[k][j-1];
21                    if(i-1 >= 0) top = vc[i-1][l];
22                    if(i-1 >= 0 && j-1 >= 0) diagonal = vc[i-1][j-1];
23                    int sum = vc[k][l] - left - top + diagonal;
24                    int rows = abs(k-i)+1;
25                    int cols = abs(l-j)+1;
26                    if(rows*cols == sum){
27                        ans++;
28                        cout<<k<<" "<<l<<endl;
29                        k++;
30                        l++;
31                    }
32                    else break;
33                }
34            }
35        }
36        return ans;
37    }
38};