#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> nums_;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        nums_ = nums;
        vector<bool> drop(nums.size(), false);
        dfs(vector<int>{}, drop, 0);
        return ans;
    }

    /*
    permute 1..n

    1 + permute drop 1
    2 + permute drop 2


    */
    void dfs(vector<int> temp, vector<bool>& drop, int i) {
        if (i == nums_.size()) {
            ans.push_back(temp);
            return;
        }
        for (int j = 0; j < nums_.size(); j++) {
            if (!drop[j]) {
                temp.push_back(nums_[j]);
                drop[j] = true;
                dfs(temp, drop, i + 1);
                temp.pop_back();
                drop[j] = false;
            }
        }
    }
};
// @lc code=end
