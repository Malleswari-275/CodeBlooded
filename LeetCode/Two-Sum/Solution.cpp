1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
5    for (int i = 0; i < numsSize - 1; i++) {
6        for (int j = i + 1; j < numsSize; j++) {
7            if (nums[i] + nums[j] == target) {
8                *returnSize = 2; // Set the size of the return array
9                int* result = (int*)malloc((*returnSize) * sizeof(int));
10                result[0] = i;
11                result[1] = j;
12                return result;
13            }
14        }
15    }
16    *returnSize = 0; // No solution found
17    return NULL;
18}