class Solution {
public:

int dp[51][51][51][5];
   
    int find(int x,int y,int z,int last)
    {
        int ans=0;

        if(dp[x][y][z][last+1]!=-1) return dp[x][y][z][last+1];
        
        if(last==-1)
        {
             if(x)
            ans=max(ans,2+find(x-1,y,z,1));
            if(y)
            ans=max(ans,2+find(x,y-1,z,2));
            if(z)
            ans=max(ans,2+find(x,y,z-1,3));
        }
        else
        {
            if(last==1)   
            {
                if(y)  
                ans=max(ans,2+find(x,y-1,z,2));
                
               
                
            }
            else if(last==2)    
            {
                if(x)  
                    ans=max(ans,2+find(x-1,y,z,1));
                
                if(z)
                    ans=max(ans,2+find(x,y,z-1,3));
                
             
            }
            else           
            {
                if(x)  
                    ans=max(ans,2+find(x-1,y,z,1));
                
                if(z)  
                    ans=max(ans,2+find(x,y,z-1,3));
                
              
            }
        }
        return dp[x][y][z][last+1]=ans;
    }
    int longestString(int x, int y, int z) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=find(x,y,z,-1);
        return ans;
    }
};
