#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int j = 0;
            while (i / 2 - j >= 0 && i / 2 + j < n
                   && s[i / 2 - j] == s[(i + 1) / 2 + j])
                j++;
            ans += j;
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.countSubstrings("ababa") << endl;
}
