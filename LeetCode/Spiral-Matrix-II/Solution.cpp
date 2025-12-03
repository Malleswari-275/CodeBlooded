1class Solution {
2public:
3    vector<vector<int>> generateMatrix(int n) {
4        vector<vector<int>>vc(n,vector<int>(n));
5        int k = 1;
6        int l = 0, r = n-1, t = 0, b = n-1;
7        while(t <= b && l <= r){
8            for(int i = l; i <= r; i++) vc[t][i] = k++;
9            t++;
10            for(int i = t; i <= b; i++) vc[i][r] = k++;
11            r--;
12            for(int i = r; i >= l; i--) vc[b][i] = k++;
13            b--;
14            if(l <= r) for(int i = b; i >= t; i--) vc[i][l] = k++;
15            l++;
16        }
17        return vc;
18    }
19};