1class Solution {
2public:
3    bool flag = false;
4    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string& word, string& s, int i, int j, int idx){
5        if(flag) return;    
6
7        if(idx == word.size()){
8            if(s == word)flag = true;
9            return;
10        }
11        
12        int n = board.size();
13        int m = board[0].size();
14        if(i < 0 || j < 0 || i >= n || j >= m) return;
15
16        vis[i][j] = true;
17        // pick
18        
19        vector<int>dx = {1,-1,0,0};
20        vector<int>dy = {0,0,1,-1};
21
22        for(int k =0; k < 4; k++){
23            int x = i + dx[k];
24            int y = j + dy[k];
25            
26            if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && board[x][y] == word[idx]){
27                s.push_back(board[x][y]);
28                dfs(board,vis,word,s,x,y,idx+1);
29                s.pop_back();
30            }
31
32        }
33        vis[i][j] = false;
34    }
35    bool exist(vector<vector<char>>& board, string word) {
36        vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
37
38        for(int i = 0; i < board.size(); i++){
39            for(int j = 0; j < board[0].size(); j++){
40                
41                if(board[i][j] == word[0]){
42                    string s = "";
43                    s += board[i][j];
44                    dfs(board,vis,word,s,i,j,1);
45                }
46                if(flag) return true;
47
48            }
49        }
50        return flag;
51    }
52};