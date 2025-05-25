#include<iostream>
using namespace std;
void countsort(int arr[],int n, int r)
{
    int outputarr[n];
    int countarr[r];
    for(int i=0;i<r;i++)
    {
        countarr[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        ++countarr[arr[i]];
    }
    for(int i=1;i<r;i++)
    {
        countarr[i]=countarr[i]+countarr[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        outputarr[--countarr[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=outputarr[i];
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
    int n,r;
    int A[20];
    cout<<"Enter the number of elements in an array: ";
    cin>>n;
    cout<<"Enter the range of the elements of the array: ";
    cin>>r;
    cout<<"Enter the elements of the array i the range (0,"<<r<<"): ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"The unsorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    countsort(A,n,r);
    printarray(A,n);
    return 0;
}