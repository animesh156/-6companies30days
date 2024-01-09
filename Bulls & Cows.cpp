class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp1,mp2;

        int n= guess.size();

        int bulls=0,cows=0;

        for(int i=0;i<n;i++){
            if(guess[i]==secret[i]) bulls++;
            else {
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }

        for(auto it: mp2){
            cows += min(it.second, mp1[it.first]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
