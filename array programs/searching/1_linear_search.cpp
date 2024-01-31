#include <bits/stdc++.h>
using namespace std;
//recursive approach
int lsr(int arr[],int k,int n){
    if(n==0){
        return -1;
    }
    if(arr[n-1]==k){
        return n-1;
    }
    else{
        return lsr(arr,k,n-1);
    }

}
int ls(int arr[],int k,int n){
 for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
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
    //int ans=lsr(arr,k,n);
    int ans=ls(arr,k,n);
    if(ans==-1){
        printf("no. not present");
    }
    else{
        printf("no. present at %d",ans+1);
    }
    return 0;
}


// Time Complexity:

// Best Case: In the best case, the key might be present at the last index. So the best case complexity is O(1)
// Worst Case: In the worst case, the key might be present at the first index i.e., opposite to the end from which the search has started in the list. So the worst case complexity is O(N)
// Average Case: O(N)