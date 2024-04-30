class Solution {
public:

    void dfs(int s,int d,vector<vector<int>>&graph,vector<vector<int>>&ans,vector<int>path){
        if(s==d){
            ans.push_back(path);
            return;
        }
        for(auto x: graph[s]){
            path.push_back(x);
            dfs(x,d,graph,ans,path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        int d=graph.size()-1;
        dfs(0,d,graph,ans,path);
        return ans;
    }
};
