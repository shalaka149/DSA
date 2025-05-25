#include<iostream>
using namespace std;
int partition(int arr[],int st,int end)
{
    int idx=st-1, pivot=arr[end];
    for(int j=st;j<end;j++)
    {
            if(arr[j]<=pivot)
            {
                idx++; 
                swap(arr[j],arr[idx]);
            }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
    
}
void quicksort(int arr[],int st, int end)
{
    if(st<end)
    {
        int pi= partition(arr,st,end);
        quicksort(arr,st,pi-1);
        quicksort(arr,pi+1,end);
    }
}
void printarray(int arr[],int n)
{
    cout<<"\nThe sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    int A[20];
    cout<<"Enter the number of elements in an array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"The unsorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    quicksort(A,0,n-1);
    printarray(A,n);
    return 0;
}