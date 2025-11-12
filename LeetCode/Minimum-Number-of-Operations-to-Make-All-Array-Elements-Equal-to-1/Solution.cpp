class Solution {
public:
    int GCD(int a, int b) {
        return b == 0 ? a : GCD(b, a % b);
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = count(nums.begin(), nums.end(), 1);

        if (cnt1 > 0) return n - cnt1;
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = GCD(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }

        if (minLen == INT_MAX) return -1; 
        return (minLen - 1) + (n - 1);
    }
};
