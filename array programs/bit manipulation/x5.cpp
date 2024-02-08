//wap to find unique no. where all no. are are present thrice
#include<bits/stdc++.h>
using namespace std;
//checking of binary representation of every no. where fill the array for like at 0th position 1 is there for 3 no.s so put 3 in arr[0].
//modulo 3 of these no. stored in array will be 0 except for that one
bool getBit(int n,int pos)
{
    return ((n & (1<<pos))!=0);
}
int setBit(int n,int pos){
    return (n | (1<<pos));
}
int unique(int arr[],int n){
    int result=0;
    for(int i=0;i<64;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(getBit(arr[j],i)){
                sum++;//check the ith bit is set or not and do sum++
            }
        }
        if(sum%3!=0){
            result=setBit(result,i);
        }
    }
    return result;
}
int main(){
     int arr[]={1,2,3,4,1,2,3,1,2,3};
    cout<<unique(arr,10);
}