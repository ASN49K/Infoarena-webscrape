#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int a[300],b[300],k=0,x,i,j,n,m,ok;

    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i];
        k=0;
    for(i=0;i<m;i++)
    {
        cin>>x;
        ok=1;
        for(j=0;j<n&&ok;j++)
        if(a[j]==x)
        {
            b[k]=x;
            k++;
            ok=0;
        }
    }
   cout<<k<<endl;
    for(i=0;i<k;i++)
        cout<<b[i]<<" ";
    return 0;
}
