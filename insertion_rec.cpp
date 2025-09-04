#include<bits/stdc++.h>
using namespace std;
void insertionsort(int arr[],int n,int i)
{



        if(i==n)return;
        int j=i;
           while(j>0&& arr[j-1] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
            i++;

        insertionsort(arr,n,i);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int i=0;
    insertionsort(arr,n,i);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

