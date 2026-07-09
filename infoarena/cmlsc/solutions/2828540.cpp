#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1025],b[1025],i,j,k,mx,c[1025][1025],st[1025];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j]) {c[i][j]=1+c[i-1][j-1];}
            else {c[i][j]=max(c[i-1][j],c[i][j-1]);}
        }
    }
    mx=c[n][m];
    i=n;
    j=m;
    fout<<mx<<'\n';
    while(mx)
    {
        if(a[i]==b[j])
        {
            k++;
            st[k]=a[i];
            mx--;
            i--;
            j--;
        }
        else if(mx==c[i-1][j]) i--;
        else j--;
    }
    for(i=k;i>=1;i--)
    {
        fout<<st[i]<<" ";
    }
    return 0;
}
