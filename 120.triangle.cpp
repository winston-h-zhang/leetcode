#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[200][200];
        dp[0][0] = triangle[0][0];
        int min_ = INT32_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (i == 0 && j == 0)
                    ;
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else if (i == j)
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1])
                               + triangle[i][j];

                if (i == n - 1)
                    min_ = min(min_, dp[i][j]);
            }
        }
        return min_;
    }
};
// @lc code=end
