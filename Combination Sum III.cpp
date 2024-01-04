class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& tmp, int i, int k, int n, vector<int> &arr){
       if(tmp.size() == k){
           if(n==0){
               ans.push_back(tmp);
               return ;
           }
           if(n<0) return;
       }
        
        if(i==arr.size()) return;
      
       if(arr[i]<=n){
           tmp.push_back(arr[i]);
           solve(ans,tmp,i+1,k,n-arr[i],arr);
           tmp.pop_back();
       }
       solve(ans,tmp,i+1,k,n,arr);
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
       
        solve(ans, tmp, 0, k, n, arr);
        return ans;
    }
};
