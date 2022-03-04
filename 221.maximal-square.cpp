#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[301][301];
        int max_ = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    int size = min(dp[i - 1][j], dp[i][j - 1]);
                    if (matrix[i - 1][j - 1] == '1') {
                        if (matrix[i - 1 - size][j - 1 - size] == '1')
                            dp[i][j] = size + 1;
                        else
                            dp[i][j] = size;
                    } else {
                        dp[i][j] = 0;
                    }
                    max_ = max(max_, dp[i][j]);
                }
            }
        }

        return max_ * max_;
    }
};
// @lc code=end
