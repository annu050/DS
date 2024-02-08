//wap to check if a given no. is a power of 2
// n =6=(0110)  //flip bits from the rightmost 1 or set bit will give us n-1
// n-1=5=(0101) 
#include<bits/stdtr1c++.h>
using namespace std;
bool ispower2(int n){
    //now as n and n-1 is 0 for power of 2 no.s i.e 0 so !0 is true
    return (n && !(n & n-1));//here n>0 for ans to be true
}
int main(){
    cout<<ispower2(16)<<endl;
}