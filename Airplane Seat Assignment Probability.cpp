
// memorization
class Solution {
public:
double f(int n,vector<double> &dp){
    if(n==1) return 1.0;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = (1.0/n + ((n-2.0)/n) * f(n-1,dp)); 
}

    double nthPersonGetsNthSeat(int n) {
        vector<double> dp(n+1,-1);
      return f(n,dp);
       
    }
};

// tabulation
class Solution {
public:

    double nthPersonGetsNthSeat(int n) {
        vector<double> dp(n+1,0);
        dp[1]=1.0;

        for(int i=2;i<=n;i++){
             dp[i] = (double) (1.0/i + ((i-2.0)/i) * dp[i-1]); 
        }
      return dp[n];
       
    }
};
