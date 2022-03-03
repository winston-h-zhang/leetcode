#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ = nums[0];
        vector<int> arr(nums.size(), 0);
        arr[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            arr[i] = max(arr[i - 1] + nums[i], nums[i]);
            max_ = max(arr[i], max_);
        }
        return max_;
    }
};
// @lc code=end
