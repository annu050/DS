#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    //3
    //  *
    // **
    //***
    //first create space print then print stars
    i=1;
    while(i<=n){
        //first print space
        int space = n-i;
        while(space){
            cout<<" ";
            space--;
        }
        //now print stars
        j=1;
        while(j<=i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
  
    }
}