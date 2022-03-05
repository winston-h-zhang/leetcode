#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int start, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<pair<int, int>> dp(n, {INT32_MAX, INT32_MAX});
        int ans = dfs(target, start, stations, 0, dp);
        return ans == INT32_MAX ? -1 : ans;
    }

    int dfs(int target,
            int start,
            vector<vector<int>>& stations,
            int i_,
            vector<pair<int, int>>& dp) {
        // recursive solution
        if (start >= target) {
            return 0;
        }
        if (i_ == stations.size()) {
            return INT32_MAX;
        }
        int ans = INT32_MAX;
        for (int i = i_; i < stations.size(); i++) {
            int dist = stations[i][0] - (i_ > 0 ? stations[i_ - 1][0] : 0);
            if (dist <= start) {
                int n;
                n = dfs(target - dist,
                        start - dist + stations[i][1],
                        stations,
                        i + 1,
                        dp);
                if (n != INT32_MAX) {
                    ans = min(ans, 1 + n);
                } else {
                    ans = min(ans, INT32_MAX);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> a = {{25, 50}, {50, 25}};
    cout << s.minRefuelStops(100, 50, a) << endl;
    return 0;
}