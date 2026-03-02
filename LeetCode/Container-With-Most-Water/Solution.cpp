1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int area = 0;
5        int i = 0;
6        int j = height.size() - 1;
7        
8        while (i < j) {
9            int currentArea = (j - i) * min(height[i], height[j]);
10            area = max(area, currentArea);
11            if (height[i] < height[j]) i++;
12            else j--;
13        }
14        return area;
15    }
16};
17