class DataStream {
    private:
     int val, n;
     int cnt=0;
     vector<int> v;

public:
    
    DataStream(int value, int k) {
        val = value;
        n = k;
    }
    
    bool consec(int num) {
        if(num == val) v.push_back(num);    
        else {                  // remove all elements fron the vector if num != val
           v.clear();
        };

        return v.size() >=n;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
