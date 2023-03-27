#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    //3
    //***
    //**
    //*
    i=1;
    while(i<=n){
        j=n-i+1;
        while(j!=0){
            cout<<"*";
            j--;
        }
        cout<<endl;
        i++;
    }

}