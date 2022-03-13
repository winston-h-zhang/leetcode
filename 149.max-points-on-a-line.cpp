#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
#define mp make_pair
/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        if (n == 1)
            return 1;
        map<int, int> vertical_lines;
        set<double> slopes;
        map<pair<double, pair<int, int>>, int> lines;
        double m;
        for (int i = 0; i < n; ++i) {
            auto xit = vertical_lines.find(points[i][0]);
            if (xit == vertical_lines.end())
                vertical_lines.emplace(points[i][0], 1);
            else {
                xit->second++;
                ans = max(ans, xit->second);
            }
            for (int j = i; j < n; ++j) {
                if (i == j)
                    continue;
                if (points[j][0] - points[i][0] == 0)
                    continue;
                m = (double)(points[j][1] - points[i][1])
                    / (points[j][0] - points[i][0]);
                slopes.insert(m);
                lines.insert(mp(mp(m, mp(points[i][1], points[i][0])), 0));
            }
        }

        cout << ">>> slopes:\n    ";
        for (auto m : slopes)
            cout << m << " ";
        cout << endl;
        cout << ">>> lines:\n";
        for (auto& l : lines)
            cout << "    " << l.first.first << " " << l.first.second.first
                 << " " << l.first.second.second << "\n";
        cout << endl;
        for (const auto& p : points) {
            for (auto& l : lines) {
                if (l.first.first
                    == (double)(p[1] - l.first.second.first)
                               / (p[0] - l.first.second.second)) {
                    l.second++;
                    ans = max(ans, l.second);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> points = {{-6, -1}, {3, 1}, {12, 3}};

    cout << s.maxPoints(points) << endl;
    return 0;
}