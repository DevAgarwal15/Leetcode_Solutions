class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        vector<int> pos(n);
        vector<int> val(n);

        for (int i = 0; i < n; i++) {
            val[i] = a[i].first;
            pos[a[i].second] = i;
        }

        vector<int> reach(n);
        int r = 0;

        for (int l = 0; l < n; l++) {
            while (r + 1 < n && (long long)val[r + 1] - val[l] <= maxDiff) {
                r++;
            }
            reach[l] = r;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            up[0][i] = reach[i];
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (u > v) swap(u, v);

            int cur = u;
            int dist = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    dist += (1 << k);
                }
            }

            if (reach[cur] >= v) {
                ans.push_back(dist + 1);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};