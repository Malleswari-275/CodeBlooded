1class Solution {
2public:
3    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
4        int sum = accumulate(gas.begin(),gas.end(),0);
5        int c = accumulate(cost.begin(),cost.end(),0);
6        if(sum < c) return -1;
7        int curr = 0;
8        int start =0;
9        for(int i = 0; i < gas.size(); i++){
10            curr += gas[i]-cost[i];
11            if(curr < 0){
12                start = i+1;
13                curr = 0;
14            }
15        }
16        return start;
17    }
18};