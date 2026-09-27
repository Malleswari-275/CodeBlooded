1class Solution {
2public:
3    string reverseParentheses(string s) {
4        stack<string> st;
5        string curr = "";
6
7        for (char ch : s) {
8            if (ch == '(') {
9                st.push(curr);
10                curr = "";
11            }
12            else if (ch == ')') {
13                reverse(curr.begin(), curr.end());
14                curr = st.top() + curr;
15                st.pop();
16            }
17            else {
18                curr += ch;
19            }
20        }
21        return curr;
22    }
23};