#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (n == k) {
            vector<int> c;
            for (int i = 1; i <= n; i++) {
                c.push_back(i);
            }
            ans.push_back(c);
            return ans;
        }
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                ans.push_back(vector<int>{i});
            }
            return ans;
        }

        ans = combine(n - 1, k);
        for (auto& v : combine(n - 1, k - 1)) {
            v.push_back(n);
            ans.push_back(v);
        }
        return ans;
    }
};
// @lc code=end
