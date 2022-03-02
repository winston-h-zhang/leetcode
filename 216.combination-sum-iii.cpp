#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    int k;
    int n;

public:
    vector<vector<int>> combinationSum3(int k_, int n_) {
        k = k_;
        n = n_;
        vector<bool> drop(9, false);
        dfs(vector<int>{}, 0, drop);
        return ans;
    }

    void dfs(vector<int> curr, int sum, vector<bool> drop) {
        int s = curr.size();
        if (s > k)
            return;
        if (sum > n)
            return;
        if (s == k && sum == n) {
            ans.push_back(curr);
            return;
        }
        int start = (s == 0) ? 1 : curr[s - 1];
        for (int i = start; i <= 9; i++) {
            if (sum + i <= n && !drop[i - 1]) {
                drop[i - 1] = true;
                curr.push_back(i);
                dfs(curr, sum + i, drop);
                drop[i - 1] = false;
                curr.pop_back();
            }
        }
    }
};
// @lc code=end
