class Solution {
public:
const int mod = 1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
    
            while(k--){
                  int ele = pq.top();
                    pq.pop();
            pq.push(ele+1);
            }
            
        long long int pro=1;
        while(!pq.empty()){
          pro *= pq.top();
            pq.pop();
           pro%=mod;
        }

        return pro;
    }
};
