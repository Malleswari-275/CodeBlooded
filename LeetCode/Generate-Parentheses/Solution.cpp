1class Solution {
2public:
3    void dfs(int openP, int closeP, string s, int n, vector<string>& vc){
4        if(closeP == openP && closeP+openP == n*2){
5            vc.push_back(s);
6            return;
7        }
8        if(openP < n) dfs(openP+1, closeP, s + "(", n, vc);
9        if(closeP < openP) dfs(openP, closeP+1, s + ")", n, vc);
10    }
11    vector<string> generateParenthesis(int n) {
12        vector<string>vc;
13        dfs(0,0,"",n,vc);
14        return vc;
15    }
16};