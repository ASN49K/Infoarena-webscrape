#include <iostream>
using namespace std;
int a[1025], b[1025], c[1025];
int main()
{

    int n,m,i,j,p=0;
    cin>>n>>m;
    for (i=1; i<=n; i++)
        cin>>a[i];
    for (j=1; j<=m; j++)
        cin>>b[j];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        if(a[i]==b[j])
        c[++p]=a[i];
    cout<<p<<endl;
    for (i=1; i<=p; i++)
       cout<<c[i]<<" ";
}
