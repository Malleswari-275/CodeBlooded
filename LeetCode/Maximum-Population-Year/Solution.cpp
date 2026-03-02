1class Solution {
2public:
3    int maximumPopulation(vector<vector<int>>& logs) {
4        vector<int> year(101, 0); 
5        for (vector<int>& log : logs) {
6            year[log[0] - 1950] += 1;  
7            year[log[1] - 1950] -= 1;
8        }
9        int maxNum = year[0], maxYear = 1950;
10        for (int i = 1; i < 101; i++) {
11            year[i] += year[i - 1];
12            if (year[i] > maxNum) { 
13                maxNum = year[i];
14                maxYear = 1950 + i;
15            }
16        }
17
18        return maxYear;
19    }
20};
21