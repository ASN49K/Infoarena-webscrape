#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int ma[1025][1025],a[1025],b[1025];
int n,m,i,j;
void afis(int ln,int co)
{
    if(ma[ln][co]!=0)
    {
        if(a[ln]==b[co])
        {
            afis(ln-1,co-1);
            out<<a[ln]<<" ";
        }
        else
        {
            if(ma[ln-1][co]>ma[ln][co-1])
                afis(ln-1,co);
            else
                afis(ln,co-1);
        }
    }
}
int main()
{
    in>>n>>m;
    for(i=1;i<=n;i++)
    {
        in>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        in>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                ma[i][j]=ma[i-1][j-1]+1;
            else
                ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
        }
    }
    out<<ma[n][m]<<endl;
    afis(n,m);
    return 0;
}
