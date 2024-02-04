//given 2d array of n*n integers.given q queries and in each
// query given a,b,,c and d print sum of square represented
// by (a,b) as top left point and (c,d) as bottom right point
//refer 2.png if not understood
#include<bits/stdc++.h>
using namespace std;
const int N= 1e3+10;
int arr[N][N];
int pf[N][N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            pf[i][j]=arr[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        // long long sum=0;//brute force
        // for(int i=a;i<=c;i++){
        //     for(int j=b;j<=d;j++){
        //         sum+=arr[i][j];
        //     }
        // }
        // cout<<sum<<endl;
        //apply prefix sum in 2d array if (3,5) then store the sum from (1,1) to (3,5)in (3,5).
        cout<<pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1];


    }
    return 0;
}