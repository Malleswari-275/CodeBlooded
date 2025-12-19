1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* left;
7    Node* right;
8    Node* next;
9
10    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
11
12    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
13
14    Node(int _val, Node* _left, Node* _right, Node* _next)
15        : val(_val), left(_left), right(_right), next(_next) {}
16};
17*/
18
19class Solution {
20public:
21    void BFS(Node* &root){
22        queue<Node*>q;
23        q.push(root);
24
25        while(!q.empty()){
26            int len = q.size();
27            for(int i = 0; i < len; i++){
28                Node* top = q.front();
29                q.pop();
30                if(i < len-1) top->next = q.front();
31                if(top->left) q.push(top->left);
32                if(top->right) q.push(top->right);
33            }
34        }
35    }
36    Node* connect(Node* root) {
37        if(!root) return root;
38        BFS(root);
39        return root;
40    }
41};