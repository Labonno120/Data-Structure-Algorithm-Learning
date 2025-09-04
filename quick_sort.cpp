#include<bits/stdc++.h>
using namespace std;
int f(int arr[],int low,int high)
{
    int pivot = low;
    int i= low;
    int j = high;
    while(i<j)
    {
        while(arr[pivot]>=arr[i])
        {
            i++;
        }
        while(arr[pivot]<arr[j])
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }

    }

    swap(arr[low],arr[j]);
    return j;
}
void quicksort(int arr[],int low,int high)
{
    if(low>=high)return;

    int partition = f(arr,low,high);
    quicksort(arr,low,partition-1);
    quicksort(arr,partition+1,high);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int low=0,high = n-1;
    quicksort(arr,low,high);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

