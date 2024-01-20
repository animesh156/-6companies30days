 int mx = 0;
        for(auto i:left){
            mx = max(mx,i);
        }
        for(auto i:right){
            mx = max(mx,n-i);
        }
        return mx;
