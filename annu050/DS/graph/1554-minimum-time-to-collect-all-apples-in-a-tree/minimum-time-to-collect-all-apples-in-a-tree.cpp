class Solution {
public:
    int dfs(int src, unordered_map<int,vector<int>>& gp, vector<bool>& hasApple, int parent) {
        int dis=0;
        for(auto i:gp[src]){
            if(i!=parent){
                int temp=dfs(i,gp,hasApple,src);
                if(hasApple[i]){
                    dis+=(2+temp);
                    hasApple[src]=true;
                }
            }
        }
        return dis;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int ans=0;
        unordered_map<int,vector<int>>gp;
        for(auto e : edges){
            gp[e[0]].push_back(e[1]);
            gp[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        return dfs(0,gp,hasApple,ans);
        
    }
};