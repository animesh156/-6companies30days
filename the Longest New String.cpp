class Solution {
public:

int dp[51][51][51][5];

int solve(int x,int y,int z,int last){
    int ans=0;

    if(dp[x][y][z][last+1]!=-1) return dp[x][y][z][last+1];


     if(last==-1){
        if(x) ans = max(ans, 2 + solve(x-1,y,z,1));
        if(y) ans = max(ans, 2 + solve(x,y-1,z,2));
           if(z) ans = max(ans, 2 + solve(x,y,z-1,3));
    }

    else {
        if(last==1) {
            if(y) ans = max(ans,2 + solve(x,y-1,z,2));
        }
        else if(last==2) {
            if(x) ans = max(ans,2 + solve(x-1,y,z,1));
            if(z) ans = max(ans, 2 + solve(x,y,z-1,3));
        }
        else {
            if(x) ans = max(ans,2 + solve(x-1,y,z,1));
            if(z) ans = max(ans,2 + solve(x,y,z-1,3));
        }
    }

    return dp[x][y][z][last+1] = ans;
}
   
   
    int longestString(int x, int y, int z) 
    {
        memset(dp,-1,sizeof(dp));
     
        return solve(x,y,z,-1);
    }
};
