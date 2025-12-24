1class Solution {
2public:
3    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
4        int apples = accumulate(apple.begin(),apple.end(),0);
5        sort(capacity.rbegin(),capacity.rend());
6        int ans = 0;
7        for(int i = 0; i < capacity.size(); i++){
8            if(apples > 0){
9                apples -= capacity[i];
10                ans++;
11            }
12            else break;
13        }
14        return ans;
15    }
16};