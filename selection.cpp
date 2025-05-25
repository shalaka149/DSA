#include<iostream>
using namespace std;
void selectionsort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
            int SI=i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[SI])
                {
                    SI=j;
                }
            }
        swap(arr[i],arr[SI]);
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
    selectionsort(A,n);
    printarray(A,n);
    return 0;
}