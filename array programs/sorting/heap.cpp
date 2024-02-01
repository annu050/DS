#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, n, largest);
    }
        
}
void heapsort(int arr[],int n){
    //iterate from last non leaf node
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    //extraction 
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
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
    heapsort(arr,n);
    printf("after sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// Time Complexity: O(N log N)
// Auxiliary Space: O(log n), due to the recursive call stack. can be O(1) in iterative implementation
// is an in-place algorithm.
// Its typical implementation is not stable but can be made stable
// slower than well-implemented QuickSort The reason for slowness is a lack of locality of reference.
// Merge sort is slightly faster than the Heap sort. But on the other hand merge sort takes extra memory. 
// Heap sort is similar to selection sort, but with a better way to get the maximum element. 
// It takes advantage of the heap data structure to get the maximum element in constant time 