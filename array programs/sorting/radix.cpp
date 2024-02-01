// Radix Sort is to do digit-by-digit sorting starting from the least significant digit 
// to the most significant digit.
#include<bits/stdc++.h>
using namespace std;
int getmax(int arr[],int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countsort(int arr[],int n, int exp){
    int output[n];
    int countArray[10]={0};
    for(int i=0;i<n;i++){
        countArray[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        countArray[i]+=countArray[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[countArray[(arr[i]/exp)%10]-1]=arr[i];
        countArray[(arr[i]/exp)%10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[],int n){
    int m= getmax(arr,n);
    for(int exp=1;m/exp>0;exp*=10){
        countsort(arr,n,exp);
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
    radixsort(arr,n);
    printf("after sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

//  time complexity of O(d * (n + b)), where d is the number of digits
//  , n is the number of elements, and b is the base of the number system being used.
//  space complexity of O(n + b)
//  Radix appears to be better than Quick Sort
