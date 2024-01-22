class Solution 
{
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        for(auto &word: words) 
            reverse(word.begin(), word.end());
        
        sort(words.begin(), words.end()); 
        
        int n = words.size();
        string str = words[0]; 
        int ans=0, wordsize;
        
       
        for(int i=1;i<n;i++) 
        {
            wordsize = str.size();
            if(words[i].compare(0, wordsize, str)) 
                ans += 1+wordsize;
            str = words[i];
        }
        ans += str.size()+1; 
        return ans;
    }
};
