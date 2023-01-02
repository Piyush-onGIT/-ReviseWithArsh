/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        map<char, int> gm, sm;

        for (int i = 0; i < n; i++) {
            gm[guess[i]]++;
            sm[secret[i]]++;
        }

        int cows = 0, bulls = 0;
        for (int i = 0; i < n; i++) {
            if (guess[i] == secret[i]) {
                bulls++;
                gm[guess[i]]--;
                sm[secret[i]]--;
            }
        }

        for (auto x : gm) {
            if (sm.find(x.first) != sm.end()) {
                cows += min(x.second, sm[x.first]);
            }
        }

        string ans = "";
        ans += to_string(bulls);
        ans += 'A';
        ans += to_string(cows);
        ans += 'B';

        return ans;
    }
};
// @lc code=end

