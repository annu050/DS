#include<bits/stdc++.h>
using namespace std;
//put 1 element sorted to its correct pos
void bubble(int arr[],int n){
    int flag=0;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag=0){
            break;
        }
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
    bubble(arr,n);
    printf("after sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// Time Complexity: O(N2)
// Auxiliary Space: O(1)
//it is stable
// it is in place
