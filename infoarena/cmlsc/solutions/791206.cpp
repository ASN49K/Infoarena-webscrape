#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

inline int maxim(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int x[1100],y[1100],a[1100][1100],k,rez[1100];

int main()
{
    int n,m,i,j;
    in>>n>>m;
    for(i=1;i<=n;++i)
        in>>x[i];
    for(i=1;i<=m;++i)
        in>>y[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            a[i][j]=maxim(a[i-1][j],a[i][j-1]);
            if(x[i]==y[j])
                a[i][j]=maxim(a[i][j],a[i-1][j-1]+1);
        }
    out<<a[n][m]<<"\n";
    for(i=n,j=m;i;)
    {
        if(x[i]==y[j])
        {
            rez[++k]=x[i];
            --i;
            --j;
            continue;
        }
        if(a[i][j-1]>a[i-1][j])
            --j;
        else
            --i;
    }
    for(i=k;i;--i)
        out<<rez[i]<<" ";
    return 0;
}
