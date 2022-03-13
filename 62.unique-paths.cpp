#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n == 1)
            return 1;
        n = n - 1 + m - 1;
        int k = min(n, m) - 1;
        long long ans = 1;
        vector<bool> js(k, false);
        for (int i = 0; i < k; ++i) {
            ans *= (n - i);
            for (int j = 0; j < k; j++) {
                if (!js[j] && ans % (j + 1) == 0) {
                    ans /= (j + 1);
                    js[j] = true;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
