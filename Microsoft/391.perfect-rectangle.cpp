/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rect) {
        map<pair<int, int>, int> m;
        for (auto i : rect) {
            m[{i[0], i[1]}]++;
            m[{i[2], i[3]}]++;
            m[{i[0], i[3]}]--;
            m[{i[2], i[1]}]--;
        }

        int c = 0;
        for (auto i : m) {
            if (abs(i.second) == 1) c++;
            else if (abs(i.second) != 1 and i.second != 0) return false;
        }

        return c == 4;
    }
};
// @lc code=end

