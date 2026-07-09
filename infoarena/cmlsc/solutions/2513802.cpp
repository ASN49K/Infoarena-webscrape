#include <bits/stdc++.h>
#define For(i,a,b,pas) for(i=a;i<=b;i+=pas)
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,d[1030][1030],sir[1030],b[1030],a[1030];
int main()
{
    fin>>m>>n;
    For(i,1,m,1)
        fin>>a[i];
    For(i,1,n,1)
        fin>>b[i];
    For(i,1,m,1)
        For(j,1,n,1)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    for (i = m, j = n; i; )
    {
        if(a[i]==b[j])
            sir[++sir[0]]=a[i] , i--,j--;
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else i--;
    }
    fout<<sir[0]<<'\n';
    for(i=sir[0];i>=1;i--)
        fout<<sir[i]<<" ";
    return 0;
}
