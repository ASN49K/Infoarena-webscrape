/// Aceasta sursa este pentru problema
/// https://www.infoarena.ro/problema/cmlsc
/// Punctaj: 100
/// Grupa de seniori

#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int d[1030][1030],a[1030],b[1030];
int n,m,i,j;
void drum(int i, int j, int k)
{
    if(k!=0)
    {
        if(a[i]==b[j])
        {
            drum(i-1, j-1, k-1);
            fout<<a[i]<<" ";
        }
        else
            if(d[i-1][j]>d[i][j-1])
                drum(i-1,j,k);
            else
                drum(i,j-1,k);
    }
}
int main()
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
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    fout<<d[n][m]<<'\n';
    drum(n,m,d[n][m]);
    return 0;
}
