#include <fstream>
#define NMAX 1030

using namespace std;

int v[NMAX][NMAX],a[NMAX],b[NMAX],sol[NMAX];
int max(int a,int b)
{
    if (a>b)
        return a;
    return b;
}

int n,m;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int main()
{
    fin>>n>>m;
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    for (int i=1; i<=m; ++i)
        scanf("%d",&b[i]);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            v[i][j]=(a[i]==b[j])?(1+v[i-1][j-1]):(max(v[i-1][j],v[i][j-1]));
    for (int i=n,j=m; i;)
        if (a[i]==b[j])
        {
            sol[++sol[0]]=a[i];
            --i;
            ++j;
        }
        else
            if (v[i-1][j]<v[i][j-1])
                ++j;
            else
                ++i;
    fout<<sol[0]<<'\n';
    for (int i=sol[0]; i>1; --i)
        fout<<sol[i]<<' ';
    fout<<sol[1];
    return 0;
}
