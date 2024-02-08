//wap to find a unique no. in an array where all numbers except one, are present twice
//use of xor operator as a^a=0,a^0=a
#include<bits/stdc++.h>
using namespace std;
int unique1(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum^arr[i];
    }
    return sum;
}
//2 4 6 7 4 5 6 2 here 5 and 7 are unique so xor of them 0010 have 1 at 1st position 
//so xor the elements who have 1 at that position and xor of result and the &^5 resut will give us 2nd unique
int setBit(int n,int pos){
    return ((n & (1<<pos))!=0);
}
void unique2(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum^arr[i];
    }
    int tempxor=sum;
    int setbit=0;
    int pos=0;
    while(setbit!=1){
        setbit=sum & 1;
        pos++;
        sum=sum>>1;
    }
    int newxor=0;
    for(int i=0;i<n;i++){
        if(setBit(arr[i],pos-1)){
            newxor=newxor^arr[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
    
}
int main(){
    int arr[]={1,2,3,1,2,3,5,7};
    //unique1(arr,7);
    unique2(arr,8);
}