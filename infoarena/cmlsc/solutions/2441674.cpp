#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],i,j,ok,n,m;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++){
        ok=0;
        for(j=1;j<=m && !ok;j++)
            if(a[i]==b[j]) ok=1;
        if(ok) g<<a[i]<< " ";
    }
    return 0;
}
