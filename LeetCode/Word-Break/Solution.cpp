1class Solution {
2public:
3    class TrieNode{
4    public:
5        TrieNode* child[26];
6        bool end;
7
8        TrieNode(){
9            for(int i = 0; i < 26; i++){
10                child[i] = NULL;
11            }
12            end = false;
13        }
14
15        void insert(string s){
16            TrieNode* node = this;
17            for(int i = 0; i < s.size(); i++){
18                if(node->child[s[i]-'a'] == NULL){
19                    node->child[s[i]-'a'] = new TrieNode();
20                }
21                node = node->child[s[i]-'a'];
22            }
23            node->end = true;
24        }
25    };
26
27
28
29    bool dfs(string s, TrieNode* node, int idx, vector<int>&dp){
30        if(idx == s.size()) return dp[idx] = true;
31        TrieNode* root = node;
32        if(dp[idx]!= -1) return dp[idx];
33        for(int i = idx; i < s.size(); i++){
34            if(node->child[s[i]-'a'] == NULL) break;
35            node = node->child[s[i]-'a'];
36            if(node->end && dfs(s,root,i+1,dp)) return dp[i] = true;
37        }
38        return dp[idx] = false;
39    }
40
41
42    bool wordBreak(string s, vector<string>& wordDict) {
43        TrieNode* root = new TrieNode();
44        for(int i = 0; i < wordDict.size(); i++){
45            root->insert(wordDict[i]);
46        }
47        vector<int>dp(s.size()+1,-1);
48
49        return dfs(s,root,0,dp);
50
51
52    }
53};