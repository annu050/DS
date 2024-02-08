//n=5 i.e 0101 so check the bit at position 2 .
// 3 2 1 0 ---->Indexing
// 0 1 0 1
#include<iostream>
using namespace std;
int getBit(int n,int pos)
{
    return (n & (1<<pos)!=0);//0101 and 0100--->1
}
int main(){
    cout<<getBit(5,2);
    return 0;
}