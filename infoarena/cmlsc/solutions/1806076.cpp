#include <fstream>
#include <bitset>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,a[1026],b[1026],d[1026][1026],sol[1026],j,k;

int main ()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
    i=n;
    j=m;
    fout<<d[n][m]<<"\n";
    k=d[n][m];
    while(k!=0)
    {
        if(a[i]==b[j])
        {
            sol[k]=a[i];
            k--;
            i--;j--;
        }
        else
            if(d[i-1][j]>d[i][j-1])
                i--;
            else
                j--;
    }
    for(i=1;i<=d[n][m];i++)
        fout<<sol[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
