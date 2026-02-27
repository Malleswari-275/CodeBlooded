1class Solution {
2private: 
3    // Helper function to check if placing a queen at position (row,col) is safe
4    bool isSafePlace(int n, vector<string>& nQueens, int row, int col) {
5        // Check if there's any queen in the same column above current position
6        for(int i=0; i<n; i++) {
7            if(nQueens[i][col] == 'Q') {
8                return false;
9            }
10        }
11
12        // Check upper-left diagonal for any queen
13        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
14            if(nQueens[i][j] == 'Q') {
15                return false;
16            }
17        }
18
19        // Check upper-right diagonal for any queen
20        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
21            if(nQueens[i][j] == 'Q') {
22                return false;
23            }
24        }
25
26        // If no conflicts found, position is safe
27        return true;
28    }
29
30    // Recursive helper function to solve N-Queens problem
31    void solveNQueens(int n, vector<vector<string>>& output, vector<string>& nQueens, int row) {
32        // Base case: if we've placed queens in all rows, we found a valid solution
33        if(row == n) {
34            output.push_back(nQueens);
35            return;
36        }
37
38        // Try placing queen in each column of current row
39        for(int col=0; col<n; col++) {
40            // If current position is safe
41            if(isSafePlace(n, nQueens, row, col)) {
42                // Place queen
43                nQueens[row][col] = 'Q';
44                // Recursively solve for next row
45                solveNQueens(n, output, nQueens, row+1);
46                // Backtrack: remove queen for trying next position
47                nQueens[row][col] = '.';
48            }
49        }
50    }
51
52public:
53    // Main function to solve N-Queens problem
54    vector<vector<string>> solveNQueens(int n) {
55        vector<vector<string>> output;  // Stores all valid solutions
56        vector<string> nQueens(n, string(n, '.')); // Initialize empty board
57        solveNQueens(n, output, nQueens, 0); // Start solving from row 0
58        return output;
59    }
60};