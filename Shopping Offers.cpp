class Solution {
public:
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int k, unordered_map<int,unordered_map<string,int>>& dp) {
        int n = price.size();
        if (k >= special.size()) {
            int sum = 0;
            for (int i = 0; i < n; ++ i) sum += needs[i] * price[i];
            return sum;
        }
        bool chk = false;
        string key = "";
        for (int i = 0; i < n; ++ i) {
            if (needs[i] < special[k][i]) chk = true;
            if (needs[i] == 10) key += "10";
            else {
                key += "0";
                key += needs[i] + '0';
            }
        }
        if (dp.find(k) != dp.end() && dp[k].find(key) != dp[k].end()) return dp[k][key];
        int res = dfs(price, special, needs, k + 1, dp);
        if (!chk) {
            for (int i = 0; i < n; ++ i) needs[i] -= special[k][i];
            res = min(res, special[k][n] + dfs(price, special, needs, k, dp));
            for (int i = 0; i < n; ++ i) needs[i] += special[k][i];
        }
        dp[k][key] = res;
        return res;
        
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<int,unordered_map<string,int>> dp;
        return dfs(price, special, needs, 0, dp);
    }
};
