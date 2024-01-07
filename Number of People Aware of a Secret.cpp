class Solution {
public:
    int solve(int i, int cur, int& n, int& delay, int& forget, vector<vector<int>>& dp) {
        
        if (cur == n+1) return 0;
        if (cur - i >= forget) return -1;
        if (dp[i][cur] != -1e9) return dp[i][cur];

      
        int sum = solve(i, cur+1, n, delay, forget, dp) % ((int)(1e9+7));
        if (cur - i >= delay) sum += (solve(cur, cur+1, n, delay, forget, dp) % ((int)(1e9+7)) + 1) % ((int)(1e9+7));

        return dp[i][cur] = sum;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1e9));
        return (solve(1, 1, n, delay, forget, dp) + 1) % ((int)(1e9+7));
    }
};
