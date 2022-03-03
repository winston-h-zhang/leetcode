#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        // use padding with INT_MAX to absorb mins
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT32_MAX));
        dp[m - 1][n] = dp[m][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int cost = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = cost > 0 ? cost : 1;
            }
        }
        return dp[0][0];
    }
};
// @lc code=end
