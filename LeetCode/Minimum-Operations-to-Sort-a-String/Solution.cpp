1class Solution {
2public:
3    int minOperations(string s) {
4        string st = s;
5        sort(st.begin(),st.end());
6        if(s == st) return 0;
7        if(st.size() == 2) return -1;
8        string left = s.substr(0,s.size()-1);
9        string right= s.substr(1);
10        cout<<left<<endl;
11        cout<<right<<endl;
12        sort(left.begin(),left.end());
13        sort(right.begin(),right.end());
14        if(left + s[s.size()-1] == st || s[0] + right == st)return 1;
15        string s1 = s;
16        sort(s1.begin(),s1.end()-1);
17        sort(s1.begin()+1,s1.end());
18        if(s1 == st) return 2;
19        string s2 = s;
20        sort(s2.begin()+1,s2.end());
21        sort(s2.begin(),s2.end()-1);
22        if(s2 == st) return 2;
23        return 3;
24    }
25};