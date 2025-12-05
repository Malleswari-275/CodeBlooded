1class Solution {
2public:
3    void parse(string s, int &real, int &imag) {
4        int plusIndex = s.find('+');    
5        real = stoi(s.substr(0, plusIndex));
6        imag = stoi(s.substr(plusIndex + 1, s.size() - plusIndex - 2));
7    }
8    string complexNumberMultiply(string num1, string num2) {
9        int a,b,c,d;
10        parse(num1,a,b);   // num1 = a + bi
11        parse(num2,c,d);   // num2 = c + di
12
13        int real = a*c - b*d;
14        int imag = a *d + b*c;
15
16        return to_string(real) + "+" + to_string(imag) + "i";
17    }
18};
19