class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        
        queue<int> q;
        q.push(0); 

      
        vector<bool> visited(n, false);
        visited[0] = true;

        while (!q.empty()) {
            int start = q.front();
            q.pop();

          
            for (int end = start + 1; end <= n; end++) {
                string word = s.substr(start, end - start);

                
                if (dict.find(word) != dict.end()) {
                  
                    if (end == n)
                        return true;

                
                    if (!visited[end]) {
                        q.push(end);
                        visited[end] = true;
                    }
                }
            }
        }

       
        return false;
    }
};
