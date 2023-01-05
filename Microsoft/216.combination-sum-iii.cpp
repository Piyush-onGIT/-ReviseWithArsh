/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> final;
    void comb(vector<int> a, int i, vector<int> ans, int sum, int k, int coins) {
        if (sum == 0 and coins == k) {
            final.push_back(ans);
            return;
        }
        if (i == a.size() or sum < 0 or coins > k) {
            return;
        }

        ans.push_back(a[i]);
        comb(a, i + 1, ans, sum - a[i], k, coins + 1);
        ans.erase(ans.begin() + ans.size() - 1);
        comb(a, i + 1, ans, sum, k, coins);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for (int i = 1; i <= 9; i++) nums.push_back(i);
        comb(nums, 0, {}, n, k, 0);
        return final;
    }
};
// @lc code=end

