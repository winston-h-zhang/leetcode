#include <cmath>
#include <iostream>
#include <queue>
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
    int minRefuelStops(int target_, int start_, vector<vector<int>>& stations) {
        int distance = 0;
        int fuel = start_;
        int ans = 0;
        int next_i = 0;
        priority_queue<int> q;
        while (distance < target_) {
            distance += fuel;
            if (distance >= target_)
                return ans;
            while (next_i < stations.size()
                   && stations[next_i][0] <= distance) {
                q.push(stations[next_i][1]);
                next_i++;
            }
            if (!q.empty()) {
                fuel = q.top();
                q.pop();
                ans++;
            } else
                return -1;
        }
        return ans;
    }
};
// @lc code=end