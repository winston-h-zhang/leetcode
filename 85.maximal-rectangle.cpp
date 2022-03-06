#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {

public:
    int largest_rectangle_area(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);
        left[0] = 0;
        for (int i = 1; i < n; ++i) {
            int _i = i - 1;
            while (_i >= 0 && heights[_i] >= heights[i]) {
                _i = left[_i] - 1;
            }
            left[i] = _i + 1;
        }
        vector<int> right(n, 0);
        right[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            int _i = i + 1;
            while (_i <= n - 1 && heights[_i] >= heights[i]) {
                _i = right[_i] + 1;
            }
            right[i] = _i - 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] + 1) * heights[i]);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i - 1][j] + 1;
                }
            }
            ans = max(ans, largest_rectangle_area(dp[i]));
        }

        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<char>> matrix
            = {{'1', '1', '1', '1', '1', '1', '1', '1'},
               {'1', '1', '1', '1', '1', '1', '1', '0'},
               {'1', '1', '1', '1', '1', '1', '1', '0'},
               {'1', '1', '1', '1', '1', '0', '0', '0'},
               {'0', '1', '1', '1', '1', '0', '0', '0'}};
    cout << s.maximalRectangle(matrix);
    return 0;
}