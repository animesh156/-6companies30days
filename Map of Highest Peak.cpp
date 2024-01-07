class Solution {
public:
    
    bool isSafe(int i, int j, int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    dp[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int lvl = 1;
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                pair<int, int> t = q.front();
                q.pop();
                
                int x = t.first, y = t.second;
                
                for(int k=0; k<4; k++){
                    
                    int X = x+dx[k], Y = y+dy[k];
                    
                    if(isSafe(X, Y, n, m)){
                        if(dp[X][Y]>lvl){
                            dp[X][Y] = lvl;
                            q.push({X, Y});
                        }
                    }
                    
                }
                
            }
            
            lvl++;
            
        }
        
        return dp;
    }
};
