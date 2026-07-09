#include <fstream>
#define nmax 1026
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[nmax];
int b[nmax];
int c[nmax][nmax],n,m;

void afis(int i,int j)
{
    if(i>n||j>m)
        return;
    if(a[i]==b[j])
    {
        fout<<a[i]<<" ";
        afis(i+1,j+1);
    }
    else
    {
        if(c[i+1][j]>c[i][j+1])
            afis(i+1,j);
        else
            afis(i,j+1);
    }
}

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(int j=1;j<=m;j++)
    {
        fin>>b[j];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
    fout<<c[n][m]<<"\n";
    afis(1,1);
    return 0;
}
