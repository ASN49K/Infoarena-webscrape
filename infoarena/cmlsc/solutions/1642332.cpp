#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,v1[1050],v2[1050],i,j,a[1050][1050],s[1050],nr;
int maxim(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>v1[i];
    for(i=1;i<=m;i++)
        fin>>v2[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
                a[i][j]=1+a[i-1][j-1];
            else
                a[i][j]=maxim(a[i-1][j],a[i][j-1]);
        }
    }
    fout<<a[n][m]<<'\n';
    for(i=n, j=m;i>0 && j>0;)
    {
        if(v1[i]==v2[j])
        {
            s[++nr]=v1[i];
            i--;
            j--;
        }
        else
        {
            if(a[i-1][j]>a[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=nr;i>=1;i--)
        fout<<s[i]<<" ";
    return 0;
}
