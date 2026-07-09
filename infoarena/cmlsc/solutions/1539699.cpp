#include <iostream>
#include <fstream>
using namespace std;
int t[1025][1025];
int main()
{ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,i,j,m,ma;
f>>n>>m;
int v[n],w[m];
   for(i=0;i<n;i++)
    f>>v[i];
   for(i=0;i<m;i++)
    f>>w[i];
    for(i=0;i<n;i++)
        t[0][1]=0;
for(i=0;i<m;i++)
    t[i][0]=0;
        for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {ma=0;
            if(w[i-1]==v[j-1]){ma=t[i-1][j-1]+1;}
            else
            {
                if(t[i][j-1]>t[i-1][j])
                {if(ma<t[i][j-1])ma=t[i][j-1];}
                else {if(ma<t[i-1][j]){ma=t[i-1][j];}}


            }
            t[i][j]=ma;
        }
    }
    g<<t[m][n]<<endl;i=m;j=n;int a,b;
    int z[1024],p=0;
    while(t[i][j])
    {ma=0;
if(w[i-1]==v[j-1]){z[p]=v[j-1];p++;}
    if(t[i-1][j]>t[i][j-1] ){a=i-1;b=j;ma=t[i-1][j];}
    else {a=i;b=j-1;ma=t[i][j-1];}
    if(ma<t[i-1][j-1]||(ma==t[i-1][j-1]&&a==i-1))
        {a=i-1;b=j-1;}

i=a;j=b;
    }

for(i=p-1;i>=0;i--)
    g<<z[i]<<" ";
    return 0;
}
