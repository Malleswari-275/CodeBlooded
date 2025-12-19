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
22
23        queue<Node*>q;
24        q.push(root);
25
26        while(!q.empty()){
27            int len = q.size();
28            for(int i = 0; i < len; i++){
29                Node* top = q.front();
30                q.pop();
31                if(i < len-1) top->next = q.front();
32                else if(i == len-1) top->next = NULL;
33                if(top->left) q.push(top->left);
34                if(top->right) q.push(top->right);
35            }
36        }
37    }
38    Node* connect(Node* root) {
39        if(!root) return root;
40        BFS(root);
41        return root;
42    }
43};