1class Solution {
2public:
3    static bool cmp(const int &a, const int&b){
4        int c1 = __builtin_popcount(a);
5        int c2 = __builtin_popcount(b);
6        if(c1 == c2) return a < b;
7        return c1 < c2;
8    }
9    vector<int> sortByBits(vector<int>& arr) {
10     sort(arr.begin(),arr.end(),cmp);   
11     return arr;
12    }
13};