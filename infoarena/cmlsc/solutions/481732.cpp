#include <fstream>

using namespace std;

int main()
{
    int m,n,a[1025],b[1025],i,j,k,ok,k2,k3,x,x2,x3,v[1025]={0},v3[1025]={0};
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");
    f>>m>>n;
    for (i=1;i<=m;i++)
        f>>a[i];
    for (i=1;i<=n;i++)
        f>>b[i];
    k=1;
    ok=0;
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (a[i]==b[j])
            {
                if (v[j]==0)
                    v[j]=k;
                ok=1;
            }
        }
        if (ok==1)
        {
            k++;
            ok=0;
        }
    }
    k2=0;x=0;k3=0;x2=0;
    for (i=2;i<=n;i++)
    {
        if (v[i]>v[i-1])
        {
            k3++;
            if (k3==1)
                x=i-1;
        }
        if (v[i]<v[i-1])
        {
            if (k3>k2)
            {
                k2=k3;
                x2=x;
                k3=0;
            }
        }
    }
    for (i=x2;i<=x2+k2;i++)
    {
        v3[i]=v[i];
    }
    x3=x2+k2;
    for (i=x2-1;i>=1;i--)
    {
        if (v[i]==v[x2]-1)
        {
            v3[i]=v[i];
            v[x2]=v[i];
        }
    }
    for (i=x3+1;i<=n;i++)
    {
        if (v[i]==v[x3]+1)
        {
            v3[i]=v[i];
            v[x3]=v[i];
        }
    }
    for (i=1;i<=n;i++)
    {
        if (v3[i]!=0)
            g<<b[v3[i]]<<" ";
    }
    return 0;
}
