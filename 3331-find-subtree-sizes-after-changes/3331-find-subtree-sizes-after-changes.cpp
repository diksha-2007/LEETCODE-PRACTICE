
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        // Build the original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<vector<int>> newTree(n);

        // Store the closest ancestor for each character
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int node) {
            int ch = s[node] - 'a';

            int old = last[ch];
            last[ch] = node;

            int newParent = parent[node];

            if (node != 0 && old != -1) {
                newParent = old;
            }

            if (node != 0) {
                newTree[newParent].push_back(node);
            }

            for (int child : adj[node]) {
                dfs(child);
            }

            last[ch] = old;
        };

        dfs(0);

        vector<int> ans(n, 1);

        // Calculate subtree sizes in the modified tree
        function<int(int)> calculate = [&](int node) {
            for (int child : newTree[node]) {
                ans[node] += calculate(child);
            }
            return ans[node];
        };

        calculate(0);

        return ans;
    }
};
