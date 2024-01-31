#include <bits/stdc++.h>
using namespace std;
int bsr(int arr[],int k,int s,int e);
int expo(int arr[],int k,int n){
    if(arr[0]==k){
        return 0;
    }
    int i=1;
    while(i<n && arr[i]<=k){
        i=i*2;
    }
    return bsr(arr,k,i/2,min(i,n-1));
}
int bsr(int arr[],int k,int s,int e){
    while (s<=e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        if (arr[mid] > k)
        {
            return bsr(arr,k,s,mid-1);
        }
        else 
        {
            return bsr(arr,k,mid+1,e);
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("enter the value of n: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int k = 10;
    int ans=expo(arr, k, n);
    if(ans==-1){
        printf("no. not present");
    }
    else{
        printf("no. present at %d",ans+1);
    }
    return 0;
}