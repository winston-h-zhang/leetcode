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

public:
    int findTargetSumWays(vector<int>& nums_, int target_) {
        ans = 0;
        nums = nums_;
        target = target_;
        dfs(0, 0);
        return ans;
    }

    void dfs(int sum, int i) {
        if (i == nums.size()) {
            if (sum == target)
                ans++;
            return;
        }

        dfs(sum + nums[i], i + 1);
        dfs(sum - nums[i], i + 1);
    }
};
// @lc code=end
