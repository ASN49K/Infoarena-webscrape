#include <fstream>

using namespace std;
int n,m,i,j,x,y,Max,nr,a[1026],b[1026],c[2026][1026];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        f>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                for(x=1;x<=nr;x++)
                {
                    if(c[x][c[x][0]]<j)
                    {
                        c[x][++c[x][0]]=j;
                        if(c[x][0]>Max)
                        {
                            Max=c[x][0];
                            y=x;
                        }
                    }
                }
                nr++;
                c[nr][++c[nr][0]]=j;
                break;
            }
        }
    }
    return 0;
}
