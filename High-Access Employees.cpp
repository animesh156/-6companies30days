class Solution {
public:
    bool check(vector<string> v) {
        int len =v.size();
        if(len < 3) return false;

        if((stoi(v[len-1]) - stoi(v[0])) < 100) return true;
        return false;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& A) {
        unordered_map<string, vector<string>> hm;
        for(auto e : A) {
            hm[e[0]].push_back(e[1]);
        }

        vector<string> ans;
        for(auto keyVal : hm) {
            string key = keyVal.first;
            
            sort(hm[key].begin(), hm[key].end());
            if(check(hm[key])) {
                ans.push_back(key);
            }
        }
        
        return ans;
    }
};
