1class Solution {
2public:
3    int minCost(vector<int>& nums1, vector<int>& nums2) {
4        map<int, int>freq1, freq2, total;
5        for (int x : nums1) {
6            freq1[x]++;
7            total[x]++;
8        }
9        for (int x : nums2) {
10            freq2[x]++;
11            total[x]++;
12        }
13        for (auto &p : total) {
14            if (p.second % 2 != 0) return -1;
15        }
16
17        map<int, int> extraInFirst, extraInSecond;
18
19        for (auto &p : total) {
20            int x = p.first;
21            int diff = freq1[x] - freq2[x];
22
23            if (diff > 0) {
24                extraInFirst[x] = diff / 2;
25            } else if (diff < 0) {
26                extraInSecond[x] = (-diff) / 2;
27            }
28        }
29
30        int answer = 0;
31
32        for (auto &p : extraInFirst) {
33            answer += p.second;
34        }
35
36        return answer;
37    }
38};