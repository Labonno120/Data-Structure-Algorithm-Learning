#include<bits/stdc++.h>
using namespace std;
void reverse(int l,int r,int a[])
{

    if(l>=r)return;
    int tem = a[l];
    a[l]=a[r];
    a[r]=tem;
    reverse(l+1,r-1,a);
}
int main()
{
    int n;
    cin>>n;
    int a[n],aa[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        aa[i]=a[i];
    }
    int l=0,r=n-1;
    reverse(l,r,a);
    bool flag = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=aa[i])
            flag=1;
    }
    if(flag)
        cout<<"False"<<endl;
    else
        cout<<"True"<<endl;
}


