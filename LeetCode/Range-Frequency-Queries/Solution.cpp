1class RangeFreqQuery {
2public:
3    class Node{
4        public:
5        int start, end;
6        map<int,int>mp;
7        Node* left;
8        Node* right;
9
10        Node(int l, int r){
11            start = l;
12            end = r;
13            left = right = NULL;
14            mp = {};
15        }
16    };
17
18    Node* root;
19
20    RangeFreqQuery(vector<int>& arr) {
21        root = build(arr,0,arr.size()-1);
22    }
23
24    Node* build(vector<int>&vc, int l, int r){
25        Node* node = new Node(l,r);
26        if(l == r){
27            node->mp[vc[l]]++;
28            return node;
29        }
30        int mid = (l+r)/2;
31        node->left = build(vc,l,mid);
32        node->right = build(vc,mid+1,r);
33        
34        node->mp = node->left->mp;
35        for(auto &it : node->right->mp){
36            node->mp[it.first] += it.second;
37        }
38        return node;
39    }
40
41    int qq(Node* rr, int left, int right, int value){
42        if(!rr || rr->start > right || left > rr->end) return 0;
43
44        if(rr->start >= left && rr->end <= right) return rr->mp[value];
45
46        int l = qq(rr->left,left,right,value);
47        int r = qq(rr->right,left,right,value);
48        return l+r;
49    }
50    
51    
52    int query(int left, int right, int value) {
53        Node* rr = root;
54        return qq(rr,left,right,value);
55    }
56};
57
58/**
59 * Your RangeFreqQuery object will be instantiated and called as such:
60 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
61 * int param_1 = obj->query(left,right,value);
62 */