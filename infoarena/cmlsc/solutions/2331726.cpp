#include <fstream>
#define nmax 1200
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[nmax],b[nmax],c[nmax][nmax];

void afis(int l,int cl)
{
    if(c==0||l==0)
        return;
    if(a[l]==b[cl])
    {
        afis(l-1,cl-1);
        fout<<a[l]<<" ";
    }
    else
        if(c[l][cl-1]>c[l-1][cl])
            afis(l,cl-1);
        else
            afis(l-1,cl);
}

int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
    fout<<c[n][m]<<"\n";
    afis(n,m);
    return 0;
}
