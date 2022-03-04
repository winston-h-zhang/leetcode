#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[10001];

        for (int i = 0; i <= amount; ++i) {
            dp[i] = i == 0 ? 0 : INT32_MAX;
            for (auto c : coins) {
                if (i - c >= 0 && dp[i - c] != INT32_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        return dp[amount] == INT32_MAX ? -1 : dp[amount];
    }
};
// @lc code=end
