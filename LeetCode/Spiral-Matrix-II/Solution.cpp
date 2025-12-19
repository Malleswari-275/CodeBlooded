1class Solution {
2public:
3    vector<vector<int>> generateMatrix(int n) {
4        vector<vector<int>>vc(n,vector<int>(n));
5        vector<int>arr;
6        for(int i = 0; i < n*n; i++)arr.push_back(i+1);
7        int k = 0;
8        int l = 0, r = n-1, t = 0, b = n-1;
9        while(t <= b && l <= r){
10            for(int i = l; i <= r; i++) vc[t][i] = arr[k++];
11            t++;
12            for(int i = t; i <= b; i++) vc[i][r] = arr[k++];
13            r--;
14            for(int i = r; i >= l; i--) vc[b][i] = arr[k++];
15            b--;
16            if(l <= r) for(int i = b; i >= t; i--) vc[i][l] = arr[k++];
17            l++;
18        }
19        return vc;
20    }
21};