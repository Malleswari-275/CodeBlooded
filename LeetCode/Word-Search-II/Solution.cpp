1
2class Solution {
3public:
4    class TrieNode {
5    public:
6        TrieNode* child[26];
7        string st;
8
9        TrieNode(){
10            for(int i = 0; i < 26; i++) child[i] = nullptr;
11            st = "";
12        }
13
14        void insert(string s){
15            TrieNode* root = this;
16            for(int i = 0; i < s.size(); i++){
17                int idx = s[i]-'a';
18                if(root->child[idx] == NULL)root->child[idx] = new TrieNode();
19                root = root->child[idx];
20            }
21            root->st = s;
22        }
23    };
24
25
26    // DFS
27
28    bool further(TrieNode* root){
29        for(int i =0 ; i < 26; i++){
30            if(root->child[i]) return true;
31        }
32        return false;
33    }
34    vector<string>ans;
35    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node){
36        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') return;
37
38        char ch = board[i][j];
39
40        if(node->child[ch-'a'] == NULL) return;
41
42        node = node->child[ch-'a'];
43
44        if(node->st != ""){
45            ans.push_back(node->st);
46            node->st = "";
47            
48            // to avoid duplicates. keeping empty after collecting the word
49        }
50        if(!further(node)) return;
51        board[i][j] = '#';
52        vector<int>dx = {1,-1,0,0};
53        vector<int>dy = {0,0,1,-1};
54
55        for(int k = 0; k < 4; k++){
56            int x = i + dx[k];
57            int y = j + dy[k];
58
59            dfs(board,x,y,node);
60        }
61        board[i][j] = ch;
62
63    }
64
65    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
66        TrieNode* root = new TrieNode();
67        for(int i = 0; i < words.size(); i++){
68            root->insert(words[i]);
69        }
70        for(int i = 0; i < board.size(); i++){
71            for(int j = 0; j < board[i].size(); j++){
72                dfs(board,i,j,root);
73            }
74        }
75
76        return ans;
77    }
78};