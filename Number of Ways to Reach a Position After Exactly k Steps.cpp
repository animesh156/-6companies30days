class Solution {
public:
    int mod = 1000000007;
    int noWays(int dst, int src, int k, vector<vector<int>>& dp) {
        if(k == 0)
            return 0;
        if(k == 1)
            if(abs(src-dst) == 1)
                return 1;
            else
                return 0;
        if(dp[dst+2000][k] != -1)
            return dp[dst+2000][k];
        return dp[dst+2000][k] = (noWays(dst-1,src,k-1,dp)%mod + noWays(dst+1,src,k-1,dp)%mod) %mod;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(4002, vector<int>(1001, -1));
        return noWays(endPos, startPos, k, dp);
    }
};
