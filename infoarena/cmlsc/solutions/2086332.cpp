#include <fstream>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int m,n;
short a[1030],b[1030],ma[1030][1030],sol[1030],k;

int main()
{
    int i,j;
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=1;i<=m;i++)
        in>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                ma[i][j]=ma[i-1][j-1]+1;
            else
                ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
    out<<ma[n][m]<<"\n";
    i=n;j=m;
    while(i!=0 and j!=0)
    {
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;
            j--;
        }
        else
            if(ma[i-1][j]>ma[i][j-1])
                i--;
            else
                j--;
    }
    for(i=k;i>=1;i--)
        out<<sol[i]<<" ";
    return 0;
}
