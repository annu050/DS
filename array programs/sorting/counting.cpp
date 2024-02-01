// Counting Sort is a non-comparison-based sorting algorithm 
#include<bits/stdc++.h>
using namespace std;
void countsort(int arr[],int n){
     vector<int> outputArray(n);
      int M = 0;
 
    for (int i = 0; i < n; i++)
        M = max(M, arr[i]);
 
    // Initializing countArray[] with 0
    vector<int> countArray(M + 1, 0);
 
    // Mapping each element of inputArray[] as an index
    // of countArray[] array
 
    for (int i = 0; i < n; i++)
        countArray[arr[i]]++;
 
    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
 
    for (int i = n - 1; i >= 0; i--)
 
    {
        outputArray[countArray[arr[i]] - 1]= arr[i];
        countArray[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=outputArray[i];
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
    countsort(arr,n);
    printf("after sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// Time Complexity:
// Worst-case: O(N+M).
// Average-case: O(N+M).
// Best-case: O(N+M).
// Auxiliary Space: O(N+M)
// is a stable algorithm.
// not in place
