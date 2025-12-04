1class Solution {
2public:
3    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
4        int top = rStart, bottom = rows-1;
5        int left = cStart, right = cols-1;
6        vector<vector<int>>ans;
7        ans.push_back({top,left});
8        int iteration = 1;
9        int i = rStart, j = cStart;
10        while(ans.size() < rows*cols){
11            for(int k = 0; k < iteration; k++){
12                j++;
13                if(i >= 0 && i < rows && j >= 0 && j < cols) ans.push_back({i,j});
14            }
15
16           for(int k = 0; k < iteration; k++){
17                i++;
18                if(i >= 0 && i < rows && j >= 0 && j < cols) ans.push_back({i,j});
19           }
20           iteration++;
21
22           for(int k = 0; k < iteration; k++){
23                j--;
24                if(i >= 0 && i < rows && j >= 0 && j < cols) ans.push_back({i,j});
25           }
26
27           for(int k = 0; k < iteration; k++){
28                i--;;
29                if(i >= 0 && i < rows && j >= 0 && j < cols) ans.push_back({i,j});
30           }
31           
32           iteration++;
33        }
34
35        return ans;
36    }
37};