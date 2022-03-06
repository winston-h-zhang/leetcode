#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=2178 lang=cpp
 *
 * [2178] Maximum Split of Positive Even Integers
 */

// @lc code=start
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1)
            return vector<long long>{};
        if (finalSum == 2)
            return vector<long long>{2};
        long long s = (int)(sqrt(finalSum) - 0.5) + 1;
        vector<long long> ans(s - 1, 0);
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = 2 * (i + 1);
        }
        if (finalSum - s * (s - 1) > ans[ans.size() - 1])
            ans.push_back(finalSum - s * (s - 1));
        else {
            ans[ans.size() - 1] += finalSum - s * (s - 1);
        }
        return ans;
    }
};
// @lc code=end
