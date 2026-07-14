class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(mx + 1, vector<int>(mx + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> ndp = dp;

            for (int g1 = 0; g1 <= mx; g1++) {
                for (int g2 = 0; g2 <= mx; g2++) {
                    if (dp[g1][g2] == 0) continue;

                    int ways = dp[g1][g2];

                    int newG1 = (g1 == 0) ? x : gcd(g1, x);
                    ndp[newG1][g2] = (ndp[newG1][g2] + ways) % MOD;

                    int newG2 = (g2 == 0) ? x : gcd(g2, x);
                    ndp[g1][newG2] = (ndp[g1][newG2] + ways) % MOD;
                }
            }

            dp = ndp;
        }

        int ans = 0;

        for (int g = 1; g <= mx; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};