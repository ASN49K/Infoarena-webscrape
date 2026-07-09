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
                    v[k]=x[i];
                    k++;
                }
                else
                  a[i][j]=max(a[i-1][j],a[i][j-1]);
               // g<<a[i][j]<<" ";
            }
           // g<<endl;
        }
    return;
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
g<<a[n][m]<<'\n';
for(int i=1; i<k; ++i)
{
    g<<v[i]<<" ";
}


}
