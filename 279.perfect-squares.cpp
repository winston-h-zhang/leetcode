#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        int dp[10001];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int min_ = INT32_MAX;
            for (int j = 1; j <= 200; j++) {
                if (j * j > i)
                    break;
                min_ = min(min_, 1 + dp[i - j * j]);
            }
            dp[i] = min_;
        }
        return dp[n];
    }
};
// @lc code=end
