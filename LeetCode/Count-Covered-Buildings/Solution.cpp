1class Solution {
2public:
3    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
4        int ans = 0;
5        vector<int>maxRow(n+1);
6        vector<int>minRow(n+1,n+1);
7
8        vector<int>maxCol(n+1);
9        vector<int>minCol(n+1,n+1);
10
11        for(auto b : buildings){
12            int x = b[0], y = b[1];
13            maxRow[y] = max(maxRow[y],x);
14            minRow[y] = min(minRow[y],x);
15
16            maxCol[x] = max(maxCol[x],y);
17            minCol[x] = min(minCol[x],y);
18        }
19
20        for(auto b : buildings){
21            int x = b[0], y = b[1];
22            if((x > minRow[y] && x < maxRow[y]) && (y > minCol[x] && y < maxCol[x])) ans++;
23        }
24        return ans;
25    }
26};