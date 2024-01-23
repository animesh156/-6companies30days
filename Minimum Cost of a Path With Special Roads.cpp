class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        map<pair<int,int>,vector<vector<int>>>graph ; 
        
        graph[{start[0],start[1]}].push_back(vector<int>{target[0],target[1],abs(target[0]-start[0])+abs(target[1]-start[1])});
        
        for(int i = 0 ; i < specialRoads.size() ; i++){
            int cost = specialRoads[i][4] ; 
            int straight = abs(specialRoads[i][2]-specialRoads[i][0])+abs(specialRoads[i][3]-specialRoads[i][1]);
            if(straight > cost){
                graph[{specialRoads[i][0],specialRoads[i][1]}].push_back(vector<int>{specialRoads[i][2],specialRoads[i][3],cost});
                cost = abs(start[0]-specialRoads[i][0]) + abs(start[1]-specialRoads[i][1]);
                graph[{start[0],start[1]}].push_back(vector<int>{specialRoads[i][0],specialRoads[i][1],cost});
            }
            else continue ; 
            for(int j = 0 ; j < specialRoads.size(); j++){
                if(i == j) continue ; 
                cost = abs(specialRoads[j][0]-specialRoads[i][2]) + abs(specialRoads[j][1]-specialRoads[i][3]) ; 
                graph[{specialRoads[i][2],specialRoads[i][3]}].push_back(vector<int>{specialRoads[j][0],specialRoads[j][1],cost}); 
            }
        }
        
        for(auto v : specialRoads){
            int cost = abs(target[0]-v[2]) + abs(target[1]-v[3]) ; 
            graph[{v[2],v[3]}].push_back(vector<int>{target[0],target[1],cost}); 
        }
        
        map<pair<int,int>,int>dist; 
        dist[{target[0],target[1]}] = INT_MAX ; 
        for(auto v : specialRoads){
            dist[{v[0],v[1]}] = INT_MAX ; 
            dist[{v[2],v[3]}] = INT_MAX ; 
        }
        
        priority_queue<pair<int,pair<int,int>>>pq; 
        pq.push({0,{start[0],start[1]}}); 
        dist[{start[0],start[1]}] = 0 ;
        
        while(!pq.empty()){
            auto t = pq.top() ; pq.pop(); 
            auto road = t.second ; 
            for(auto x : graph[road]){
                int new_dist = -t.first + x[2] ; 
                if(dist[{x[0],x[1]}] > new_dist){
                    dist[{x[0],x[1]}] = new_dist ; 
                    pq.push({-dist[{x[0],x[1]}],{x[0],x[1]}}); 
                }
            }
        }
        
        return dist[{target[0],target[1]}] ;
    }
};
