class Solution {
    const long long MOD = 1e9 + 7;
    int dp[(1<<15)][15];
    
    long long dfs(vector<int>& nums, int mask, int prev) {
        if (mask == (1<<nums.size())-1) return 1;
        if (prev!=-1 && dp[mask][prev] != -1)
            return dp[mask][prev];
        
        int ans{0};
        for(int i=0; i<nums.size(); i++) {
            if ((mask&(1<<i)) == 0 && (prev == -1 || nums[i]%nums[prev]==0 || nums[prev]%nums[i]==0))
                ans = (ans + dfs(nums, (mask|(1<<i)), i))%MOD;
        }
        
        if(prev != -1)
            dp[mask][prev] = (ans%MOD);
        return (ans%MOD);
    }
public:
    int specialPerm(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return dfs(nums, 0, -1)%MOD;
    }
};
