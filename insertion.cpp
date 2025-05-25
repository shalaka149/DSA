#include<iostream>
using namespace std;
void insertionsort(int arr[],int n)
{
        for (int i=1;i<n;i++)
        {
            int curr=arr[i];
            int prev= i-1;
            while(prev>=0 && arr[prev]>curr)
            {
                arr[prev+1]=arr[prev];
                prev--;
            }
            arr[prev+1]=curr;
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
    insertionsort(A,n);
    printarray(A,n);
    return 0;
}