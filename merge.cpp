#include<iostream>
using namespace std;
void merge(int arr[],int st,int mid,int end)
{
    int temp[20];
    int count=0;
    int i=st,j= mid+1;
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            temp[count++]=arr[i++];
        }
        else
        {
            temp[count++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[count++]=arr[i++];
    }
    while(j<=end)
    {
        temp[count++]=arr[j++];
    }
    for(int id=0;id<count;id++)
    {
        arr[st+id]= temp[id];
    }
    
}
void mergesort(int arr[],int st, int end)
{
    if(st<end)
    {
        int mid= st+(end-st)/2;
        mergesort(arr,st,mid);
        mergesort(arr,mid+1,end);
        merge(arr,st,mid,end);
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
    mergesort(A,0,n-1);
    printarray(A,n);
    return 0;
}