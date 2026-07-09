#include <iostream>
#include <cmath>
using namespace std;
int a[601][601],n,d,m,j,c=0,ok,i;
int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>a[i][j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j+=2)
        {
            ok=1;
            if(a[i][j]==0||a[i][j]==1)ok=0;
            for(d=2; d<=sqrt(a[i][j]); d++)
                if(a[i][j]%d==0)ok=0;
            if(ok==1)
                c++;
        }
    cout<<c;
    return 0;
}
