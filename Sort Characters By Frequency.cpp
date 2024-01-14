class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        string ans="";

        while(!pq.empty()){
            int freq = pq.top().first;
            while(freq--){
           ans+=pq.top().second;
            }
            pq.pop();
        }

        return ans;
    }
};
