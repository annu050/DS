//find out sum from L to r for different cases in an array.
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
int arr[N];
int pf[N];
int main(){
    int n;
    cout<<"enter the value of n";
    cin>>n;
    for(int i=1;i<=n;i++){//1 based to handle the 0th index case 
        cin>>arr[i];
        pf[i]=pf[i-1]+arr[i];
    }
    cout<<"enter the total test cases:";
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cout<<"value of l ansd r";
        cin>>l>>r;
        // long long sum=0;
        // for(int i=l;i<=r;++i){
        //     sum+=arr[i];//O(N)+O(T*N)=10^10 WHICH IS HUGE SO USE OF PREFIX SUM
        // }
        // cout<<sum<<endl;
        cout<<pf[r]-pf[l-1]<<endl;
    }
}
//        r
//|------------------|
//|---------|--------|
//    l        req.
//so r-l=required
