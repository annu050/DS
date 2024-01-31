#include <bits/stdc++.h>
using namespace std;
//recursive approach
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
int bs(int arr[], int k, int n)
{
    int s = 0, e =n-1;
    
    while (s<=e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        if (arr[mid] > k)
        {
            e = mid - 1;
        }
        else 
        {
            s = mid + 1;
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
    //int ans=bs(arr, k, n);
    int ans=bsr(arr,k,0,n-1);
    if(ans==-1){
        printf("no. not present");
    }
    else{
        printf("no. present at %d",ans+1);
    }
    return 0;
}

// Best Case: O(1)
// Average Case: O(log N)
// Worst Case: O(log N)

