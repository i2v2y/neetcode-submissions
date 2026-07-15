class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (const string& left : dp[j]) {
                    for (const string& right : dp[i - j - 1]) {
                        dp[i].push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return dp[n];
    }
};
