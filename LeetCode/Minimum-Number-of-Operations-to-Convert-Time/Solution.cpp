1class Solution {
2public:
3    int convertTime(string current, string correct) {
4        int curr = stoi(current.substr(0,2))*60 + stoi(current.substr(3,2));
5        int corr = stoi(correct.substr(0,2))*60 + stoi(correct.substr(3,2));
6
7        int diff = corr - curr;
8        int ans = 0;
9
10        ans += diff / 60;
11        diff %= 60;
12
13        ans += diff / 15;
14        diff %= 15;
15
16        ans += diff / 5;
17        diff %= 5;
18
19        ans += diff;
20
21        return ans;
22    }
23};
24