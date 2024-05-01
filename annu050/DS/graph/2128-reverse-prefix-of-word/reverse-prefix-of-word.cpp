class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans;
        int r=-1;
        for(int i=0;i<word.length();i++){
            ans+=word[i];
            if(word[i]==ch){
                reverse(ans.begin(),ans.end());
                r=i;
                break;
            }
        }
        if(r==-1){
            return ans;
        }
        for(int i=r+1;i<word.length();i++){
            ans+=word[i];
        }
        return ans;
    }
};