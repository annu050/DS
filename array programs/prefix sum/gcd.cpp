//print gcd after we exclude no. from l to r
#include<bits/stdc++.h>
using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,q;
//         cin>>n>>q;
//         int arr[n];
//         for(int i=1;i<=n;i++){
//             cin>>arr[i];
//         }
//         while(q--){
//             int l,r;
//             cin>>l>>r;
//             int gc=0;//gcd with same no. is no.
//             for(int i=1;i<=l-1;i++){
//                 gc=__gcd(gc,arr[i]);//use of inbuilt function i.e logn
//             }
//             for(int i=r+1;i<=n;i++){
//                 gc=__gcd(gc,arr[i]);
//             }
//             cout<<gc<<endl;
//         }
//     }
// }

//sum of n over all test cases will be less than or equal to 10^6
//use of prefix and suffic to reduce time
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int arr[n+10];
        int fwd[n+10];
        int bwd[n+10];
        fwd[0]=bwd[n+1]=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=n;i++){
            fwd[i]=__gcd(fwd[i-1],arr[i]);
       }
       for(int i=n;i>=1;i--){
            bwd[i]=__gcd(bwd[i+1],arr[i]);
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            cout<< __gcd(fwd[l-1],bwd[r+1])<<endl;
        }
    }
    return 0;
}