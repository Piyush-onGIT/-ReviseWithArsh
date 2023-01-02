/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &dvis) {
        vis[node] = 1;
        dvis[node] = 1;
        for (auto x : adj[node]) {
            if (!vis[x]) {
                if (dfs(x, node, adj, vis, dvis)) return true;
            }
            else if (dvis[x]) return true;
        }
        dvis[node] = 0;
        return false;
    }
    bool cyclic(vector<int> adj[], int v) {
        vector<int> vis(v, 0);
        vector<int> dvis(v, 0);
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis, dvis)) return true;
            }
        }
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> adj[n];

        for (int i = 0; i < a.size(); i++) {
            adj[a[i][1]].push_back(a[i][0]);
        }
        return !cyclic(adj, n);
    }
};
// @lc code=end

