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
        for (auto s : dp)
            cout << s.first << " ";
        cout << endl;
        return ans == INT32_MAX ? -1 : ans;
    }

    int dfs(int target,
            int start,
            vector<vector<int>>& stations,
            int i_,
            vector<pair<int, int>>& dp) {
        // recursive solution
        if (start >= target) {
            if (i_ < dp.size())
                dp[i_] = {0, start};
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
                // if we have a dp solution, call dp
                // dp[i] is the shortest path from the i + 1 station
                if (i < dp.size() - 1 && dp[i + 1].first != INT32_MAX
                    && start - dist + stations[i][1] >= dp[i + 1].second) {
                    n = dp[i + 1].first;
                } else {
                    //
                    n = dfs(target - dist,
                            start - dist + stations[i][1],
                            stations,
                            i + 1,
                            dp);
                }
                if (n != INT32_MAX) {
                    ans = min(ans, 1 + n);
                } else {
                    ans = min(ans, INT32_MAX);
                }
            }
        }
        dp[i_] = {ans, start};
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> a
            = {{13, 21},
               {26, 115},
               {100, 47},
               {225, 99},
               {299, 141},
               {444, 198},
               {608, 190},
               {636, 157},
               {647, 255},
               {841, 123}};
    cout << s.minRefuelStops(1000, 299, a) << endl;
    return 0;
}