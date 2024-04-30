class Solution {
public:
    int mx=0;
    void dfs(unordered_map<int,vector<int>> &mp,int headID,vector<int>& informTime,int ans){
        mx=max(mx,ans);
        for(auto emp: mp[headID]){
            ans+=informTime[headID];
            dfs(mp,emp,informTime,ans);
            ans-=informTime[headID];
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans=0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1){
                mp[manager[i]].push_back(i);
            }
        }
        dfs(mp,headID,informTime,ans);
        return mx;
    }
};