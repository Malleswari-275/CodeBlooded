1class Solution {
2public:
3    string AddStrings(string s1, string s2){
4        // reverse(s1.begin(),s1.end());
5        // reverse(s2.begin(),s2.end());
6        if(s1.size() < s2.size()){
7            for(int i = s1.size(); i < s2.size(); i++) s1.insert(0,"0");
8        }
9        else {
10            for(int i = s2.size(); i < s1.size(); i++) s2.insert(0,"0");
11        }
12        int carry = 0;
13        int sub;
14        string result = "";
15        int n = max(s1.size(),s2.size()) - 1;
16        for(int i = n; i >= 0; i--){
17            if(i < s1.size() && i < s2.size()){
18                sub = (s1[i]-'0') + (s2[i]-'0') + carry;
19            }
20            else if(i < s1.size() && i >= s2.size()) sub = (s1[i]-'0') + carry;
21            else sub = (s2[i]-'0') + carry;
22            int add = sub%10;
23            carry = sub/10;
24            result += to_string(add);
25        }
26        if(carry != 0) result += to_string(carry);
27        reverse(result.begin(),result.end());
28        return result;
29    }
30    string multiply(string num1, string num2) {
31        if(num1 == "0" || num2 == "0") return "0";
32        string n1,n2;
33        if(num1.size()<=num2.size()){
34            n1 = num1;
35            n2 = num2;
36        }
37        else{
38            n1 = num2;
39            n2 = num1;
40        }
41        // n1 contains less or equal digits than n2
42        // cout<<n2;
43        int zero_cnt = -1;
44        string ans;
45        vector<string>vc;
46        for(int i = n1.size()-1; i >= 0; i--){
47            string s = "";
48            zero_cnt++;
49            int carry = 0;
50            for(int j = n2.size()-1; j >= 0; j--){
51                int sub = (n1[i]-'0')*(n2[j]-'0') + carry;
52                // cout<<sub<<endl;
53                int add = sub%10;
54                carry = sub/10;
55                // cout<<add<<" "<<carry<<endl;
56                s += to_string(add);
57                if(j == 0 && carry != 0) s+=to_string(carry);
58            }
59            reverse(s.begin(),s.end());
60            for(int k = 0; k < zero_cnt; k++) s += "0";
61            // cout<<s<<endl;
62            ans = AddStrings(ans,s);
63            cout<<ans<<" ";
64        }
65        return ans;
66    }
67};