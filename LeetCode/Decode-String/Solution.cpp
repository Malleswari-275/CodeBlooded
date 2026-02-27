1class Solution {
2public:
3    string decodeString(string s) {
4        stack<char>st;
5        for(int i = 0; i < s.size(); i++){
6            if(s[i] != ']') st.push(s[i]);
7            else{
8                string curr = "";
9                while(st.top() != '['){
10                    curr = st.top() + curr;
11                    st.pop();
12                }
13                st.pop();
14                string number = "";
15                while(!st.empty() && isdigit(st.top())){
16                    number = st.top() + number;
17                    st.pop();
18                }
19                int repeat = stoi(number);
20                while(repeat--){
21                    for(int j = 0; j < curr.size(); j++) st.push(curr[j]);
22                }
23            }
24        }
25        s = "";
26        while(!st.empty()){
27            s = st.top() + s;
28            st.pop();
29        }
30        return s;
31    }
32};