class Solution {
    private:
         vector<int> z_function(string str){
             vector<int>z(str.size());
             int l=0,r=0;
             for(int i=1;i<str.size();i++){
                 if(i>r){
                     l=r=i;
                     while(r<str.size() && str[r]==str[r-l])r++;
                     z[i]=r-l;
                     r--;
                 }
                 else if(i<=r){
                     int idx=i-l;
                     if(i+z[idx]<=r){
                         z[i]=z[idx];
                     }
                     else{
                         l=i;
                         while(r<str.size() && str[r]==str[r-l])r++;
                         z[i]=r-l;
                         r--;
                     }
                 }
             }
             return z;
             
         }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>v1=z_function(a+"$"+s);
        vector<int>v2=z_function(b+"$"+s);
        vector<int>v11;
        for(int i=0;i<v1.size();i++){
            if(v1[i]==a.size()){
                v11.push_back(i-a.size()-1);
            }
        }
        // set<int>st;
        vector<int>v22;
        for(int i=0;i<v2.size();i++){
            if(v2[i]==b.size()){
                v22.push_back(i-b.size()-1);
                
            }
        }
        vector<int>ans;
        for(int i=0;i<v11.size();i++){
            for(int j=0;j<v22.size();j++){
                if(abs(v11[i]-v22[j])<=k){
                    ans.push_back(v11[i]);
                    break;
                }
            }
        }
        return ans;
        
    }
};