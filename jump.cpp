#include<iostream>
using namespace std;
int jumpsearch(int arr[],int n,int tar,int m)
{
    int step=m;
    int prev=0;
    while(arr[min(step,n)-1]<tar)
    {
        prev=step;
        step+=m;
        if(prev>=n)
        {
            return -1;
        }
    }
    for(int i=prev;i<min(step,n);i++)
    {
        if(arr[i]==tar)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n,tar,res,m;
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
    cout<<"Enter the indexes to jump: ";
    cin>>m;
    res=jumpsearch(A,n,tar,m);
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