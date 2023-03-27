#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    //n=4
    //    1
    //   121
    //  12321
    // 1234321
//first see it as 3 triangles 
//1.space triangle
//2.   1
//    12
//   123 
//  1234
//3.  end last tringle where it is starting from i-1 

i=1;
while(i<=n){
    //first print space i.e n-i
    int space=n-i;
    while(space){
        cout<<" ";
        space--;
    }
    //print 1st triangle
    j=1;
    while(j<=i){
        cout<<j;
        j++;
    }
    //print 3rd triangle
    int start=i-1;
    while(start!=0){
        cout<<start;
        start--;
    }

    cout<<endl;
    i++;
}

}