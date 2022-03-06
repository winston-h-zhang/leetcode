#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};
// @lc code=end
