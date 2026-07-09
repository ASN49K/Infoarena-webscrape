#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int s[1030][1030],a[1030],b[1030],i,j,n,m,mx,v[1030];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                s[i][j]=s[i-1][j-1]+1;
            else
                s[i][j]=max(s[i-1][j],s[i][j-1]);
    }
    fout<<s[n][m]<<"\n";
    i=n;
    j=m;
    mx=s[n][m];
    while(s[i][j]>0)
    {
        if(a[i]==b[j])
        {
            v[mx]=a[i];
            i--;
            j--;
            mx--;
        }
        else if(s[i][j-1]>s[i-1][j])
                j--;
        else
            i--;
    }
    for(i=1;i<=s[n][m];i++)
        fout<<v[i]<<" ";
}
