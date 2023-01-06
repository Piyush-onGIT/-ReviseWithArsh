/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<int> dp(n, 1);

        int mx = 1, prev = -1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] % a[j] == 0) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    mx = max(mx, dp[i]);
                }
            }
        }

        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] == mx) {
                if (prev == -1) {
                    mx--;
                    prev = a[i];
                    ans.push_back(prev);
                }
                else if (prev % a[i] == 0) {
                    mx--;
                    prev = a[i];
                    ans.push_back(a[i]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
