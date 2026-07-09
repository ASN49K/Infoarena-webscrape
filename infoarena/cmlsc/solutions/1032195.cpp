#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int a[1030],b[1030],c[300],k1=0,k2=0,x,i,j,n,m,ok,poz=0;

    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i];
        k1=0;
    for(i=0;i<m;i++)
        cin>>b[i];
    for(i=0;i<m;i++)
    {
        ok=1;
        for(j=poz;j<n&&ok;j++)
        if(a[j]==b[i])
        {
            c[k1]=b[i];
            k1++;
            ok=0;
            poz=j;
        }
    }poz=0;
    for(i=0;i<n;i++)
    {
        ok=1;
        for(j=poz;j<m&&ok;j++)
        if(b[j]==a[i])
        {
            c[k2]=a[i];
            k2++;
            ok=0;
            poz=j;
        }
    }


    if(k1>k2){
   cout<<k1<<endl;
    for(i=0;i<k1;i++)
        cout<<c[i]<<" ";
    }
    else
    {
        cout<<k2<<endl;
    for(i=0;i<k2;i++)
        cout<<c[i]<<" ";
    }
    return 0;
}
