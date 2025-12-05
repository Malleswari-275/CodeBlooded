1class Solution {
2public:
3    int CountOnes(vector<vector<int>>&vc,int i, int j){
4        int cnt = 0;
5        int m = vc.size(), n = vc[0].size();
6        if(i+1 < m){
7            if(vc[i+1][j] == 1) cnt++;
8            if(j+1 < n) if(vc[i+1][j+1] == 1) cnt++;
9            if(j-1 >= 0) if(vc[i+1][j-1] == 1) cnt++;
10        }
11        if(i-1 >= 0){
12            if(vc[i-1][j] == 1) cnt++;
13            if(j-1 >= 0) if(vc[i-1][j-1] == 1) cnt++;
14            if(j+1 < n) if(vc[i-1][j+1] == 1)cnt++;
15        }
16        if(j-1 >= 0)if(vc[i][j-1] == 1) cnt++;
17        if(j+1 < n) if(vc[i][j+1] == 1) cnt++;
18        return cnt;
19    }
20    void gameOfLife(vector<vector<int>>& board) {
21        vector<vector<int>>duplicate = board;
22
23        for(int i = 0; i < board.size(); i++){
24            for(int j = 0; j < board[i].size(); j++){
25                int ones = CountOnes(duplicate,i,j);
26                cout<<ones<<" ";
27                if(duplicate[i][j] == 0){
28                    if(ones == 3) board[i][j] = 1;
29                }
30                else{
31                    if(ones < 2) board[i][j] = 0;
32                    else{
33                        if(ones > 3) board[i][j] = 0;
34                    }
35                }
36            }
37        }
38    }
39};