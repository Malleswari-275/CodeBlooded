1class Solution {
2public:
3    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
4        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
5        // priority_queue<int,vector<int>,greater<int>>pq;
6        for(int i =0; i < arr.size(); i++){
7            pq.push({abs(x-arr[i]),arr[i]});
8            // pq.push(abs(x-arr[i]));
9        }
10        vector<int>res;
11        while(k--){
12            res.push_back(pq.top().second);
13            pq.pop();
14        }
15        sort(res.begin(),res.end());
16        return res;
17    }
18};