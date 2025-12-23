1class Solution {
2public:
3    int sumOddLengthSubarrays(vector<int>& arr) {
4        int sum = 0;
5        for(int i = 0; i < arr.size(); i++){
6            int contrib = (i+1)*(arr.size()-i);
7            double odd = contrib/2.0;
8            if(arr.size()%2 != 0) odd = ceil(odd);
9            sum += odd*arr[i];
10        }
11        return sum;
12    }
13};