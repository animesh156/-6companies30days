class Solution {
public:

    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());

        bool flag = true;
        long long m = mass;
              
        for(int i=0;i<asteroids.size();i++){
               if(m<asteroids[i]) {
                   flag = false;
                   break;
               }
               m+=asteroids[i];
        }

        if(flag) return true;
        return false;
    }
};
