#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int dp[101];
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1] - nums[i - 1] + nums[i]);
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};
// @lc code=end
