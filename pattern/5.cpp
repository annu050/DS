#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    // 3
    // 123
    // 456
    // 789
    i=1;
    int p=1;

    while(i<=n){
        j=1;
        while(j<=n){
            if(p<=n*n){
                  cout<<p;//or just put this p and increment it no need of condition
                  p++;
            }
          
           j++;
        }
    i++;
    cout<<endl;
    }
}