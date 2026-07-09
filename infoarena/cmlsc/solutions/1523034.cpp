#include <iostream>
#include <fstream>
using namespace std;
#define mini(n,m) n>m?m:n
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,k,p,a[1024],b[1024],c[1024][1024];

int maxim(int x,int y)
{
    if (x>y)
        return x;
    return y;
}

void creare()
{
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(a[i]==b[j])
                    c[i][j]=c[i-1][j-1]+1;
                else
                    c[i][j]=maxim(c[i-1][j],c[i][j-1]);

}

void afisare(int x,int y)
{
    if(k)
    {
        if(a[x]==b[y])
        {
            k--;
            afisare(x-1,y-1);
            g<<a[x]<<" ";
        }
        else
        {
            if(c[x-1][y]>c[x][y-1])
                afisare(x-1,y);
            else
                afisare(x,y-1);
        }
    }
}

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    creare();
    k=c[n][m];
    g<<k<<'\n';
    afisare(n,m);
    f.close();
    g.close();
}
