//wap to count the no. of ones in binary representation of a no.
//n & n-1 has same bits as n except the rightmost set bit
#include<bits/stdc++.h>
using namespace std;
int count(int n){
    int c=0;
    while(n>0){
        n=n&n-1;
        c++;
    }
    return c;
}
int main(){
    cout<<count(19);
}
