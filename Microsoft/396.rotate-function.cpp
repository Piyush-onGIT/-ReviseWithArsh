/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        int ans = 0, sum = 0;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            ans += a[i] * i;
            sum += a[i];
        }

        int mx = ans;
        for (int i = n - 1; i >= 0; i--) {
            ans += sum - (a[i] * n);
            mx = max(mx, ans);
        }
        return mx;
    }
};
// @lc code=end

