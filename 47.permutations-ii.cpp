#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> nums;
    int n;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums_) {
        nums = nums_;
        n = nums.size();
        vector<bool> drop(n, false);
        dfs(vector<int>{}, 0, drop);
        return ans;
    }

    void dfs(vector<int> temp, int i, vector<bool> drop) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }

        unordered_set<int> used;
        for (int j = 0; j < n; j++) {
            if (!drop[j] && used.find(nums[j]) == used.end()) {
                used.insert(nums[j]);
                drop[j] = true;
                temp.push_back(nums[j]);
                dfs(temp, i + 1, drop);
                drop[j] = false;
                temp.pop_back();
            }
        }
    }
};
// @lc code=end
