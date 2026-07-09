class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> pow10(n + 1, 1), invPow10(n + 1, 1);
        long long inv10 = 700000005; // modular inverse of 10 mod 1e9+7

        for (int i = 1; i <= n; i++) {
            pow10[i] = pow10[i - 1] * 10 % MOD;
            invPow10[i] = invPow10[i - 1] * inv10 % MOD;
        }

        vector<int> cntNonZero(n + 1, 0);
        vector<int> digitSum(n + 1, 0);
        vector<long long> weighted(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            cntNonZero[i + 1] = cntNonZero[i] + (d != 0);
            digitSum[i + 1] = digitSum[i] + d;
            weighted[i + 1] = weighted[i];

            if (d != 0) {
                int pos = cntNonZero[i + 1];
                weighted[i + 1] = (weighted[i + 1] + d * invPow10[pos]) % MOD;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int sum = digitSum[r + 1] - digitSum[l];
            int nonZeroTillR = cntNonZero[r + 1];

            long long val = (weighted[r + 1] - weighted[l] + MOD) % MOD;
            long long x = val * pow10[nonZeroTillR] % MOD;

            ans.push_back(x * sum % MOD);
        }

        return ans;
    }
};