#include<fstream>
#include<algorithm>
#define maxn 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[maxn],b[maxn],i,j,n,m,r[maxn][maxn];

void write(int x,int y)
{
    if(!x||!y)return;
    if(a[x]==b[y])
        write(x-1,y-1);
    else
        if(r[x-1][y]>r[x][y-1])
            write(x-1,y);
        else
            write(x,y-1);
    if(a[x]==b[y])
        g<<a[x]<<" ";
}

int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i)
        f>>a[i];
    for(j=1;j<=m;++j)
        f>>b[j];

    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])
                r[i][j]=r[i-1][j-1]+1;
            else
                r[i][j]=max(r[i][j-1],r[i-1][j]);

    g<<r[n][m]<<"\n";
    write(n,m);
    g<<"\n";

    f.close();
    g.close();

    return 0;
}

