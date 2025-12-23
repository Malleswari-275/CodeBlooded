1class Solution {
2public:
3    int sumOddLengthSubarrays(vector<int>& arr) {
4        int sum = 0;
5        for(int i = 0; i < arr.size(); i++){
6            for(int j = i; j < arr.size(); j++){
7                if((j-i+1)%2 != 0){
8                    for(int k = i; k <= j; k++){
9                        sum += arr[k];
10                    }
11                }
12            }
13        }
14        return sum;
15    }
16};