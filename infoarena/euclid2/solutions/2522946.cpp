#include <iostream>
#include <fstream>
using namespace std;
ifstream f("vecini_buni.in");
ofstream g("vecini_buni.out");

int v[1001],w[1001],z[1001];
int main()
{
    int n,m,k,maxi=0,c=0,i,j,y,h,a,b,x,u,cop;
    f>>n>>m>>k;

    for(i=0;i<=m+1;i++)
        v[i]=2;

    w[0]=2;
    w[m+1]=2;
    z[0]=2;
    z[m+1]=2;
    for(i=1;i<=k;i++)
    {
        f>>a>>b;
        if(a==1)
        {
            w[b]=1;
        }
        else if(a==2)
        {
            z[b]=1;
        }
        else if(a==3)
        {
            h=i;
            cop=h;
            break;
        }
    }
    for(j=1;j<=n;j++)
    {
    w[0]=2;
    w[m+1]=2;
    z[0]=2;
    z[m+1]=2;
    for(i=1;i<=m;i++)
    {
        x=0;
        if(w[i]==v[i-1])
        {
            x++;
        }
        if(w[i]==v[i])
        {
            x++;
        }
        if(w[i]==v[i+1])
        {
            x++;
        }
        if(w[i]==w[i-1])
        {
            x++;
        }
        if(w[i]==w[i+1])
        {
            x++;
        }
        if(w[i]==z[i-1])
        {
            x++;
        }
        if(w[i]==z[i])
        {
            x++;
        }
        if(w[i]==z[i+1])
        {
            x++;
        }

        if(x>maxi)
        {
            maxi=x;
            c=1;
        }
        else if(x==maxi)
        {
            c++;
        }
    }
    for(i=1;i<=m;i++)
    {
        v[i]=w[i];
    }
    for(i=1;i<=m;i++)
    {
        w[i]=z[i];
    }
    for(i=1;i<=m;i++)
    {
        z[i]=0;
    }

        z[b]=1;

    while(h<=k)
    {
        f>>a>>b;
        if(h==cop)
        {
            y=a;
        }
         h++;
         if(a!=y)
        {
            break;
        }
        z[b]=1;
    }
    if(j==n-1)
    {
        for(i=1;i<=m;i++)
            z[i]=2;
    }
    }
    g<<maxi<<" "<<c;
    return 0;
}
