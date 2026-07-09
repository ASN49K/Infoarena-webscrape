#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int v[1024][1024],s1[1024],s2[1024],sol[1024];
int main()
{
    int n,m;
    fin>>n>>m;
    for (int i=1;i<=n;i++)
        fin>>s1[i];
    for (int j=1;j<=m;j++)
        fin>>s2[j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (s1[i]==s2[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    fout<<v[n][m]<<"\n";
    int c=0;
    int i=n,j=m;
    while (c<v[n][m])
    {
        if (s1[i]==s2[j])
        {
            sol[++c]=s1[i];
            i--;
            j--;
        }
        else
        {
            if (v[i-1][j]>v[i][j-1])
                i--;
            else
                j--;
        }
    }
    for (i=c;i>0;i--)
        fout<<sol[i]<<" ";
    return 0;
}
