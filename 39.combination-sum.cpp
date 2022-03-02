#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> candidates;
    int target;

public:
    vector<vector<int>> combinationSum(vector<int>& _candidates, int _target) {
        candidates = _candidates;
        target = _target;
        dfs(vector<int>{}, 0);
        return ans;
    }

    void dfs(vector<int> curr, int sum) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        int n = curr.size();
        for (auto i : candidates) {
            if (sum + i <= target && (n == 0 || (n > 0 && curr[n - 1] <= i))) {
                curr.push_back(i);
                dfs(curr, sum + i);
                curr.pop_back();
            }
        }
    }
};
// @lc code=end
