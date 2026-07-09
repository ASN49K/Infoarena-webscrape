

#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int xx,y,max1,i,j,ok,x[5],n,m,a[1025],b[1025],k,v[1025][1025],sir[1025];



int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)f>>a[i];
    for(i=1; i<=m; i++)f>>b[i];

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m&&!ok; j++)
            if(a[i]==b[j])
                v[i][j]=1+v[i-1][j-1];
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);

    }
j=m;
    for(i=n;i>=1;)
    {
        if(a[i]==b[j])
        {
            k++;
            sir[k]=a[i];
            i--;j--;
        }
        else
            if(v[i-1][j]<v[i][j-1])
            j--;
        else
            i--;
    }


    g<<k<<'\n';

    for(i=k; i>=1; i--)
        g<<sir[i]<<" ";

    return 0;
}


