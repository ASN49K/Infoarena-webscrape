#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],m,n,i,j,d[1025][1025],hossz,ezi,ezj,sor[1025];
int main()
{
    f>>n;
    f>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];

    hossz=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
            if(d[i][j]>hossz)
            {
                hossz=d[i][j];
                ezi=i;
                ezj=j;
            }
        }

    i=hossz;
    while(i>0)
    {
        while(d[ezi][ezj]==d[ezi-1][ezj])
            ezi--;
        while(d[ezi][ezj]==d[ezi][ezj-1])
            ezj--;
        sor[i]=a[ezi];
        ezi--;
        ezj--;
        i--;
    }
    g<<hossz<<"\n";
    for(i=1;i<=hossz;i++)
        g<<sor[i]<<" ";
}
