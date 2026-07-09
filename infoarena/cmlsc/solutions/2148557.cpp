#include <bits/stdc++.h>
#define nmax 1024

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m,n,i,j,x[nmax],y[nmax],v[nmax],k;

void Interclasare()
{
    i=1;
    j=1;
    while(i<=n && j<=m)
    {
        if(x[i]<y[j]) i++;

        else if(x[i]>y[j]) j++;

        else if(x[i]==y[j])
        {
            v[++k]=x[i];
            i++, j++;
        }
    }
    g<<k<<"\n";
    for(i=1; i<=k; i++)
        g<<v[i]<<" ";
}

void Read()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>x[i];
    for(i=1; i<=m; i++)
        f>>y[i];

    sort(x+1,x+n+1);
    sort(y+1,y+m+1);

    Interclasare();
}

int main()
{
    Read();
    return 0;
}
