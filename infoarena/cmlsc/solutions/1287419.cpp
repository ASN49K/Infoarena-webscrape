#include <fstream>
using namespace std;
ifstream in("magicmatrix.in");
ofstream out("magicmatrix.out");
int n,a[501],stop,sD1,sD2,sT,m[501][501],t;
int main()
{
    in>>t;
    for(int ii=1;ii<=t;ii++)
    {
        in>>n;
        sD1=0;
        sD2=0;
        sT=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                in>>m[i][j];
                sT=sT+m[i][j];
            }
            sD1=sD1+m[i][i];
            sD2=sD2+m[i][n-i+1];
        }
        if(sD1==sD2 && sD1*n==sT)
            out<<"YES"<<'\n';
        else
            out<<"NO"<<'\n';
    }
    return 0;
}
