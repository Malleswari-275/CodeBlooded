class Solution {
public:
    bool zero(int num){
        while(num){
            int r = num%10;
            if(r == 0) return true;
            num /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            int a = i;
            int b = n-i;
            if(!zero(a) && !zero(b) && (a+b == n)) return {a,b};
        }
        return {};
    }
};