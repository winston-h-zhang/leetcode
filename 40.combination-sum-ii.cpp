#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> candidates;
    int target;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates_, int target_) {
        candidates = candidates_;
        target = target_;
        vector<bool> drop(candidates.size(), false);
        dfs(vector<int>{}, 0, drop);
        return ans;
    }

    void dfs(vector<int> curr, int sum, vector<bool> drop) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        int n = curr.size();
        unordered_set<int> used;
        for (int i = 0; i < candidates.size(); i++) {
            if (sum + candidates[i] <= target
                && (n == 0 || n > 0 && curr[n - 1] <= candidates[i]) && !drop[i]
                && used.find(candidates[i]) == used.end()) {
                // start if
                used.insert(candidates[i]);
                drop[i] = true;
                curr.push_back(candidates[i]);
                dfs(curr, sum + candidates[i], drop);
                drop[i] = false;
                curr.pop_back();
            }
        }
    }
};
// @lc code=end
