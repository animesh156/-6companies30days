class ThroneInheritance {
public:

    unordered_map<string,vector<string>> t;
    map<string,int> m;
    string a;
    ThroneInheritance(string kingName) {
        a=kingName;
        m[a]=1;
    }
    
    void birth(string parentName, string childName) {
        t[parentName].push_back(childName);
        m[childName]=1;
        m[parentName]=1;
    }
    
    void death(string name) {
        m[name]=2;
    }
    void dfs(string name,vector<string>& v){
        if(m[name]==1){
            v.push_back(name);
        }

        for(string it:t[name]){
            dfs(it,v);
        }
        return;
    }
    vector<string> getInheritanceOrder() {
        vector<string> v;
        dfs(a,v);
        return v;
    }
};
