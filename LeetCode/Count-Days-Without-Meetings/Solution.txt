1class Solution {
2public:
3    vector<vector<int>> merge(vector<vector<int>>& meetings){
4        vector<vector<int>>vc;
5        vc.push_back(meetings[0]);
6        for(int i = 1; i < meetings.size(); i++){
7            if(meetings[i][0] <= vc.back()[1]){
8                vc.back()[1] = max(vc.back()[1],meetings[i][1]);
9            }
10            else vc.push_back(meetings[i]);
11        }
12        return vc;
13    }
14    int countDays(int days, vector<vector<int>>& meetings) {
15        
16        sort(meetings.begin(),meetings.end());
17        vector<vector<int>>vc = merge(meetings);
18        int working = 0;
19        for(int i = 0; i < vc.size(); i++){
20            working += vc[i][1] - vc[i][0] + 1;
21        }
22        return days - working;
23    }
24};