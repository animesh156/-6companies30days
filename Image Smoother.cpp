class Solution {
public:
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};


bool valid(int i,int j,int r,int c){
    return (i>=0 && i<r && j>=0 && j<c);
}


    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
          int r=img.size();
          int c=img[0].size();
        vector<vector<int>> ans(r, vector<int>(c,0));

        for(int i=0;i<r;i++){

            for(int j=0;j<c;j++){

                int sum=img[i][j];
                int cnt=1;

                for(int k=0;k<8;k++){

                    if(valid(i+dx[k],j+dy[k],r,c)){
                        sum+=img[i+dx[k]][j+dy[k]];
                        cnt++;
                    }
                }

                ans[i][j]= (sum/cnt);

            }
        }

        return ans;
    }
};
