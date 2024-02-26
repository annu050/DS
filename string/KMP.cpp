//use of prefix function i.e where the prefix and suffix substr
// for a point is samethen write its length in the array
#include<bits/stdc++.h>
using namespace std;
//tc:O(N)
vector<int> prefix_function(string s){
    int n=s.size();
    vector<int>pi(n,0);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        //if the string don't match then check the previous all previous ones if there is someone
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]){//if equla then piche waala + the new one 
            j++;
        }
        pi[i]=j;
    }
    return pi;
}
int main(){
    string s="sha";
    vector<int> res=prefix_function(s);
    string t="anususha tiwari";
    int pos=-1;
    int i=0,j=0;
    while(i<t.size()){
        if(t[i]==s[j]){
            j++;
            i++;

        }
        else{
            if(j!=0){
                j=res[j-1];//go back in s string 
            }
            else{
                i++;
            }
        }
        if(j==s.size()){
            pos=i-s.size();
            break;
        }
        
    }
    cout<<pos;
}
//TC:O(S+T)