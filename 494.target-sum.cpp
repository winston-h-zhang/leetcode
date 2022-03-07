#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
private:
    int ans;
    vector<int> nums;
    int target;
    int total;
    int memo[21][2001];

public:
    int findTargetSumWays(vector<int>& nums_, int target_) {
        ans = 0;
        nums = nums_;
        target = target_;
        total = 0;
        for (auto& n : nums_)
            total += n;
        for (int i = 0; i < 21; ++i) {
            for (int j = 0; j < 2001; ++j) {
                memo[i][j] = -1;
            }
        }
        return dfs(0, 0);
    }

    int dfs(int sum, int i) {
        if (i == nums.size()) {
            if (sum == target)
                return 1;
            return 0;
        }
        int add, sub;
        if (memo[i + 1][sum + nums[i] + total] == -1) {
            add = dfs(sum + nums[i], i + 1);
            memo[i + 1][sum + nums[i] + total] = add;
        } else {
            add = memo[i + 1][sum + nums[i] + total];
        }

        if (memo[i + 1][sum - nums[i] + total] == -1) {
            sub = dfs(sum - nums[i], i + 1);
            memo[i + 1][sum - nums[i] + total] = sub;
        } else {
            sub = memo[i + 1][sum - nums[i] + total];
        }
        return add + sub;
    }
};
// @lc code=end
