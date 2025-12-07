1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& asteroids) {
4        stack<int>st;
5        st.push(asteroids[0]);
6        int i = 1;
7        while(i < asteroids.size()){
8            if(asteroids[i] >= 0 || st.empty() || st.top() < 0) st.push(asteroids[i++]);
9            else{
10                int tp = st.top();
11                if(abs(asteroids[i]) == tp){
12                    st.pop();
13                    i++;
14                }
15                else if(abs(asteroids[i]) > tp ) st.pop();
16                else i++;
17            }
18        }
19        vector<int>vc;
20        while(!st.empty()){
21            vc.push_back(st.top());
22            st.pop();
23        }
24        reverse(vc.begin(),vc.end());
25        return vc;
26    }
27};