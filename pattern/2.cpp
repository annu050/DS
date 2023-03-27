#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    // 3 
    // 111
    // 222
    // 333
    i=1;
    while(i<=n){
        j=1;
        while(j<=n){
            cout<<i;
            j+=1;
        }
        i+=1;
        cout<<endl;
    }
}