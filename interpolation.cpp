#include<iostream>
using namespace std;
int interpolationsearch(int arr[],int n,int tar)
{
   int high=n-1;
   int low=0;
   while(tar>=arr[low] && tar<=arr[high] && low<=high)
   {
        int probe=(high-low)*(tar-arr[low])/(arr[high]-arr[low]);
        //cout<<"probe:"<<probe;
        if(arr[probe]==tar)
        {
            return probe;
        }
        else if(arr[probe]<tar)
        {
            low=probe+1;
        }
        else
        {
            high=probe-1;
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
    res=interpolationsearch(A,n,tar);
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