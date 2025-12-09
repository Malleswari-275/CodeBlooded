1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        deque<int>dq;
5        vector<int>vc;
6        for(int i = 0; i < k; i++){
7            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
8            dq.push_back(i);
9        }
10        for(int i = k; i < nums.size(); i++){
11            vc.push_back(nums[dq.front()]);
12            if(!dq.empty() && dq.front() == i-k) dq.pop_front();
13            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
14            dq.push_back(i);
15        }
16        vc.push_back(nums[dq.front()]);
17        return vc;
18    }
19};