#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short int a[1025],b[1025],n,m,mat[1025][1025],v[1025];
int maxi(int a,int b)
{
    if(a>b) return a;
    return b;
}
void rezolv()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                mat[i][j]=1+mat[i-1][j-1];
            else
                mat[i][j]=maxi(mat[i-1][j],mat[i][j-1]);
    int i=n,j=m,nrc=0;
    while(i!=0 && j!=0)
    {
        if(a[i]==b[j]) v[++nrc]=a[i],i--,j--;
        else
        if(mat[i-1][j]>mat[i][j-1]) i--;
        else j--;
    }
    fout<<mat[n][m]<<'\n';
    for(int i=nrc;i>=1;i--)
        fout<<v[i]<<' ';
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    rezolv();
    return 0;
}
