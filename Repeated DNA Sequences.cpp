class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string, int> freq;

        vector<string> ans;

        for(int i=0;i < n-9;i++){
            freq[s.substr(i,10)]++;
        }

        for(auto it: freq){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
