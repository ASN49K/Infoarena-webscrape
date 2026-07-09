#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,j,nr,k;
int a[1030], b[1030];
int LCS[2030][2030];
int v[1030];

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                LCS[i][j]= 1+ LCS[i-1][j-1];
            else
                LCS[i][j]= max(LCS[i-1][j], LCS[i][j-1]);
        }
    fout<< LCS[n][m] << '\n';
    i=n;
    j=m;
    while(i>0&&j>0)
    {
        if(LCS[i][j]==LCS[i-1][j-1]+1)
            v[++k]=a[i],i--,j--;
        else
        {
            if(LCS[i-1][j]<LCS[i][j-1])
                j--;
            else
                i--;
        }

    }
    for(i=k;i>=1;i--)
        fout<< v[i] << ' ';
    fout<< '\n';
    return 0;
}
