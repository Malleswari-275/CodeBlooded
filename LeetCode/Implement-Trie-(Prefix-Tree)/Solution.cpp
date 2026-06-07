1class Trie {
2public:
3    Trie* child[26];
4    bool end;
5    Trie() {
6       for(int i = 0; i < 26; i++){
7            child[i] = NULL;
8       } 
9       end = false;
10    }
11    
12    void insert(string word) {
13        Trie* temp = this;
14        for(int i = 0; i < word.size(); i++){
15            if(temp->child[word[i]-'a'] == NULL){
16                temp->child[word[i]-'a'] = new Trie();
17            }
18            temp = temp->child[word[i]-'a'];
19        }
20        temp->end = true;
21    }
22    
23    bool search(string word) {
24        Trie* node = this;
25        for(int i = 0; i < word.size(); i++){
26            if(node->child[word[i]-'a'] == NULL) return false;
27            node = node->child[word[i]-'a'];
28        }
29        return node->end;
30    }
31    
32    bool startsWith(string prefix) {
33        Trie* node = this;
34        for(int i = 0; i < prefix.size(); i++){
35            if(node->child[prefix[i]-'a'] == NULL) return false;
36            node = node->child[prefix[i]-'a'];
37        }
38        return true;
39
40    }
41};
42
43/**
44 * Your Trie object will be instantiated and called as such:
45 * Trie* obj = new Trie();
46 * obj->insert(word);
47 * bool param_2 = obj->search(word);
48 * bool param_3 = obj->startsWith(prefix);
49 */