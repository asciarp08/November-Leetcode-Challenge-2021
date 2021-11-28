/**
Time = O(n*2^n)
Space = O(n*2^n)
**/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> paths;
        queue<pair<int,vector<int>>> q; //node, path
        q.push({0,{0}});
        
        while(!q.empty()){
            auto [u,path] = q.front(); q.pop();
            if(u==n-1){
                paths.push_back(path);
                continue;
            }
            for(auto v:graph[u]){
                path.push_back(v);
                q.push({v, path});
                path.pop_back();
            }
                
        }
        return paths;
    }
};
