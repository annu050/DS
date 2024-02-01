#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int beg,int end){
    int pivot=arr[end];
    //Index of smaller element and Indicate
    //the right position of pivot found so far
    int i=beg-1;
    for(int j=beg;j<end;j++){
        //If current element is smaller than the pivot
        if(arr[j]<pivot)
        {
            //Increment index of smaller element
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return (i+1);
}
void quicksort(int arr[],int beg,int end){
    if(beg<end)
  {
    // pi is the partition return index of pivot
    int pi=partition(arr,beg,end);
     
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quicksort(arr,beg,pi-1);
    quicksort(arr,pi+1,end);
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
    quicksort(arr,0,n-1);
    printf("after sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// Time Complexity:
// Best Case: Ω (N log (N))   divides the array into roughly equal halves.
// Average Case: θ ( N log (N))
// Worst Case: O(N2)  When the array is already sorted and the pivot is always chosen as the smallest or largest element.
// Auxiliary Space: O(1)
// It is not a stable sort//relative order not preserved if two elements are same 
// it is in place
