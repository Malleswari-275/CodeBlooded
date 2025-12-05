1class Solution {
2public:
3    string AddStrings(string s1, string s2){
4        if(s1.size() < s2.size()){
5            for(int i = s1.size(); i < s2.size(); i++) s1.insert(0,"0");
6        }
7        else {
8            for(int i = s2.size(); i < s1.size(); i++) s2.insert(0,"0");
9        }
10        int carry = 0;
11        int sub;
12        string result = "";
13        int n = max(s1.size(),s2.size()) - 1;
14        for(int i = n; i >= 0; i--){
15            sub = (s1[i]-'0') + (s2[i]-'0') + carry;
16            int add = sub%10;
17            carry = sub/10;
18            result += to_string(add);
19        }
20        if(carry != 0) result += to_string(carry);
21        reverse(result.begin(),result.end());
22        return result;
23    }
24    string multiply(string num1, string num2) {
25        if(num1 == "0" || num2 == "0") return "0";
26        string n1,n2;
27        if(num1.size()<=num2.size()){
28            n1 = num1;
29            n2 = num2;
30        }
31        else{
32            n1 = num2;
33            n2 = num1;
34        }
35        int zero_cnt = -1;
36        string ans;
37        vector<string>vc;
38        for(int i = n1.size()-1; i >= 0; i--){
39            string s = "";
40            zero_cnt++;
41            int carry = 0;
42            for(int j = n2.size()-1; j >= 0; j--){
43                int sub = (n1[i]-'0')*(n2[j]-'0') + carry;
44                int add = sub%10;
45                carry = sub/10;
46                s += to_string(add);
47                if(j == 0 && carry != 0) s+=to_string(carry);
48            }
49            reverse(s.begin(),s.end());
50            for(int k = 0; k < zero_cnt; k++) s += "0";
51            ans = AddStrings(ans,s);
52        }
53        return ans;
54    }
55};