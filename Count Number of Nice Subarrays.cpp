class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
          int count = 0;
          int n=a.size();
 vector<int> prefix(n+1,0);
    int odd = 0;
 
   
    for (int i = 0; i < n; i++) 
    {
 
        prefix[odd]++;
 
      
        if (a[i] & 1)
            odd++;
 
     if (odd >= k)
            count += prefix[odd - k];
    }
 
    return count;
    }
};
