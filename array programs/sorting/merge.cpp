#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int s,int mid,int e){
    int i=s,j=mid+1,k=0,temp[e-s+1];
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=e){
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
    }
    for(int i=0;i<k;i++){
        arr[s+i]=temp[i];
    }
}
void mergesort(int arr[],int s,int e){
    int mid;
    if(s<e){
        mid=(e+s)/2;
        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
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
    mergesort(arr,0,n-1);
    printf("after sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// Time Complexity: O(N log(N))
// recurrence relation: T(n) = 2T(n/2) + θ(n)
// Auxiliary Space: O(N)
// it is stable
// not in place
// External sorting: Merge sort is commonly used in external sorting,
//  where the data to be sorted is too large to fit into memory.
// Not always optimal for small datasets: For small datasets, Merge sort has a higher time complexity 