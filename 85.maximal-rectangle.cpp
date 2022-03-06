#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int max_rect(int i, int j, vector<vector<char>>& matrix) { return 0; }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<pair<int, int>>> dp(
                m + 1, vector<pair<int, int>>(n + 1, {0, 0}));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << ">>> i j: " << i - 1 << " " << j - 1 << "\n";
                if (matrix[i - 1][j - 1] == '0')
                    continue;
                int h = max(dp[i - 1][j].first + 1, dp[i][j - 1].first);
                int w = max(dp[i - 1][j].second, dp[i][j - 1].second + 1);
                cout << "h w: " << h << " " << w << "\n";

                int _i = i - dp[i - 1][j].first - 1;
                while (_i > 0 && matrix[_i - 1][j - 1] == '1' && i - _i + 1 < h)
                    _i--;
                h = min(h, i - _i + 1);
                int _j = j - dp[i - 1][j].second - 1;
                while (_j > 0 && matrix[i - 1][_j - 1] == '1' && j - _j + 1 < w)
                    _j--;
                w = min(w, j - _j + 1);
                cout << "h w: " << h << " " << w << "\n";
                int c_i = i - dp[i][j - 1].first - 1;
                int c_j = j - dp[i - 1][j].second - 1;
                pair<int, int> corner = (c_i >= 0 && c_j >= 0)
                                                ? dp[c_i][c_j]
                                                : make_pair(0, 0);
                h = min(h, 1 + dp[i][j - 1].first + corner.first);
                w = min(w, 1 + dp[i - 1][j].second + corner.second);
                cout << "h w: " << h << " " << w << "\n";
                dp[i][j] = {h, w};
            }
        }
        for (auto& r : dp) {
            for (auto& c : r) {
                cout << "(" << c.first << " " << c.second << ") ";
            }
            cout << "\n";
        }
        cout << "\n";
        return 0;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<char>> matrix
            = {{'1', '0', '1', '0', '0'},
               {'1', '0', '1', '1', '1'},
               {'1', '1', '1', '1', '1'},
               {'1', '0', '0', '1', '0'}};
    cout << s.maximalRectangle(matrix);
    return 0;
}