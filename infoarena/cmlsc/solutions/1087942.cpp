#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[1025],w[1025],a[1025][1025],z[1025];
int main()
{
    int x,y,i,j,n=0;
    f>>x>>y;
    for(i=1;i<=x;i++)
        f>>v[i];
    for(i=1;i<=y;i++)
        f>>w[i];
    for(i=1;i<=x;i++)
        for(j=1;j<=y;j++)
            if(v[i]==w[j])
                a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
    i=x;
    j=y;
    while(i>0 && j>0)
    {
        if(v[i]==w[j])
        {
            z[++n]=v[i];
            i--;
            j--;
        }
        else if(a[i-1][j]<a[i][j-1])
            j--;
        else
            i--;
    }
    g<<n<<"\n";
    for(i=n;i>=1;i--)
        g<<z[i]<<" ";
    f.close();
    g.close();
    return 0;
}
