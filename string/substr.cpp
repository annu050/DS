//BRUTE FORCE
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="na";
    string t="Apna Collegena";
    int S=s.size(),T=t.size();
    for(int i=0;i<T-S+1;i++){//T-S+1 as if s is suppose 5 then obviouly it won't be present at last or n-1 or n-1 pos
        if(t.substr(i,S)==s){
            cout<<"Found at index "<<i<<"\n";
        }
    }
}
//TC:O(ST)