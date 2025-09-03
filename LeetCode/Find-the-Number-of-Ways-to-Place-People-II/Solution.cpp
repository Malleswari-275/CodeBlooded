class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),compare);
        int ans = 0;
        for(int i = points.size()-1; i >= 0; i--){
            int x2 = points[i][0];
            int y2 = points[i][1];
            int min_y = 1e9;
            for(int j = i-1; j >= 0; j--){
                int x1 = points[j][0];
                int y1 = points[j][1];
                if(y1 >= min_y || y2 > y1) continue;
                ans++;
                min_y = y1;
            }
        }
        return ans;
    }
};