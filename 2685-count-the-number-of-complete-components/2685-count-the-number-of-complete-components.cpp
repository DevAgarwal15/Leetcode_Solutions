class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (sz[pa] < sz[pb]) swap(pa, pb);

        parent[pb] = pa;
        sz[pa] += sz[pb];
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& e : edges) {
            unite(e[0], e[1]);
        }

        vector<long long> edgeCount(n, 0);

        for (auto& e : edges) {
            int root = find(e[0]);
            edgeCount[root]++;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                long long nodes = sz[i];
                long long expectedEdges = nodes * (nodes - 1) / 2;

                if (edgeCount[i] == expectedEdges) {
                    ans++;
                }
            }
        }

        return ans;
    }
};