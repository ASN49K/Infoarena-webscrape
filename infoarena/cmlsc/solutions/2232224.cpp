#include <iostream>
#include <fstream>
using namespace std;
int m,n,a[1025],b[1025],o,sol[1025],marc[1025][1025],ind;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
{
    in>>m>>n;
    for(int i=1;i<=m;i++)
    {
        in>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        in>>b[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                marc[i][j]++;
            }
            else marc[i][j]=max(marc[i-1][j],marc[i][j-1]);
        }
    }
    int i=m,j=n;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            sol[ind++]=a[i];
            i--;j--;
        }
        else if(marc[i-1][j]<marc[i][j-1])i--;
        else j--;
    }
    out<<marc[m][n]<<'\n';
    for(int o=ind-1;o>=0;o--)
    {
        out<<sol[o]<<' ';
    }
    return 0;
}
