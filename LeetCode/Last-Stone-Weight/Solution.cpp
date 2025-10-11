class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }
        while(!pq.empty() && pq.size() > 1){
            int maxi1 = pq.top();
            pq.pop();
            int maxi2 = pq.top();
            pq.pop();
            int diff = maxi1-maxi2;
            pq.push(diff);
        }
        return pq.top();
    }
};