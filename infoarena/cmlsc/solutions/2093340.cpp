#include<bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x[1030],y[1030],a[1030][1030],m,n,v[1030],k=1;
void dinamica()
{
    for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; ++j)
            {
                if(x[i]==y[j])
                {
                    a[i][j]=a[i-1][j-1] +1;
                }
                else
                  a[i][j]=max(a[i-1][j],a[i][j-1]);
               // g<<a[i][j]<<" ";
            }
           // g<<endl;
        }
    return;
}
///asta face matricea si vede lungimea cmlsc in a[n][m]
int invers(int n,int m,int k)
{
    if(n>=1 && m>=1)
    if(x[n]==y[m])
    {
        v[k]=x[n];
        invers(n-1,m-1,k-1);
    }
    else
    {
        if(a[n-1][m]<a[n][m-1])
        {
            invers(n,m-1,k);
        }
        else
        {
            invers(n-1,m,k);
        }
    }
   return 0;
}
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        f>>x[i];
    }
    for(int j=1; j<=m; j++)
    {
        f>>y[j];
    }
dinamica();
invers(n,m,a[n][m]);
g<<a[n][m]<<'\n';
for(int i=1; i<=a[n][m]; ++i)
{
    g<<v[i]<<" ";
}


}
