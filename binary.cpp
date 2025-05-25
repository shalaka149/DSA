#include<iostream>
using namespace std;
int binarysearch(int arr[],int st,int end,int tar)
{
    while(st<=end)
    {
        int mid=(st+end)/2;
        if(tar>arr[mid])
        {
            st=mid+1;
        }
        else if(tar<arr[mid])
        {
            end=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    int n,tar,res;
    int A[20];
    cout<<"Enter the number of elements in an array: ";
    cin>>n;
    cout<<"Enter the elements of the array in ascending order: ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"Enter the target to search: ";
    cin>>tar;
    res=binarysearch(A,0,n-1,tar);
    if(res!=-1)
    {
        cout<<"The index is: "<<res;
    }
    else
    {
        cout<<"Target not found in array.";
    }
    return 0;
}