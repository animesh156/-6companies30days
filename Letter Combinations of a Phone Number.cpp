class Solution {
public:
    void solve(string digits, string ans, int idx, vector<string> st, vector<string> &res){
        if(idx >= digits.length()){
            res.push_back(ans);
            return;
        }
        int stringIndex = (digits[idx]-'0');
        string value = st[stringIndex];
        for(int i = 0; i<value.length(); i++){
            ans.push_back(value[i]);
            solve(digits, ans, idx+1, st, res);
            ans.pop_back();
        }
    }

    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits == "")
            return res;
        vector<string> st= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string ans="";
        solve(digits, ans, 0, st, res);
        return res;
    }
};
