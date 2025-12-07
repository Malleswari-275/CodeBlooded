1class Solution {
2public:
3    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
4        long long Mass = mass;
5        sort(asteroids.begin(),asteroids.end());
6        for(int i = 0; i < asteroids.size(); i++){
7            if(asteroids[i] <= Mass) Mass += asteroids[i];
8        
9        }
10        if(Mass >= asteroids[asteroids.size()-1]) return true;
11        return false;
12    }
13};