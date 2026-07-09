#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[2001][2001],x,y,i,j,b[2001],c[2001],w[2011],p,d;
int main()
{
 fin>>x>>y;
 for(i=1; i<=x; i++)
    {fin>>b[i];
     }
 for(i=1; i<=y; i++)
    {fin>>c[i];
     }
 for(i=1; i<=y; i++)
    for(j=1; j<=x; j++)
    if(c[i]==b[j])
    a[i][j]=a[i-1][j-1]+1;
    else
        a[i][j]=max(a[i-1][j],a[i][j-1]);
    fout<<a[y][x]<<endl;
    d=a[y][x];
    while(y>0&&x>0)
    {

        if(b[y]==c[x])
        {
            p++;
            w[p]=c[y];
            y--;
            x--;
        }
        else
        {
            if(a[y-1][x]>=a[y][x-1])
                y--;
            else
                x--;
        }
    }
    for(i=p; i>=1; i--)
        fout<<w[i]<<' ';

}
