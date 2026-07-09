#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define pb push_back

int c[1027][1027],n,m,x,maxi=0;
vector <int> a;
vector <int> b;
vector <int> sol;

void citire()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        a.pb(x);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        b.pb(x);
    }
}

void afis()
{
    printf("%d\n",sol.size());
    for(int i=sol.size()-1;i>=0;i--)
        printf("%d ",sol[i]);
}

void rev()
{
    int q=c[n][m],i=n,j=m;
    while(q!=0)
    {
        if(a[i-1]==b[j-1])
        {
            sol.pb(a[i-1]);
            i-=1;
            j-=1;
        }
        else
        {
            if(c[i-1][j]>=c[i][j-1])
                i-=1;
            else j-=1;
        }
        q=c[i][j];
    }
}

void rezolvare()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i-1]==b[j-1])
                c[i][j]=max(c[i-1][j],c[i][j-1])+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    rev();
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    rezolvare();
    afis();
    return 0;
}
