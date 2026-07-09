#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1001][1001],x,y,i,j,b[1001],c[1001],w[1011],p,d;
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

        if(a[y][x]==a[y-1][x-1]+1)
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
