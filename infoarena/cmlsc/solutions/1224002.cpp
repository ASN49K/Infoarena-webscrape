#include <fstream>

using namespace std;
#define MX 1050

int n,m, a[MX],b[MX], c[MX][MX],i,r[2*MX];

int mx(int a, int b)
{
    if (a>b) return a;
    else return b;
}

void pd()
{
    int i,j;

    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            {   c[i][j]= mx(c[i-1][j],c[i][j-1] );
                if (a[i]==b[j] )
                    c[i][j]=mx(c[i][j], c[i-1][j-1]+1 ); }
}

void drum()
{
    int i=n, j=m, k ;
    while (i>0 && j>0)
    {
        if (a[i]==b[j] && c[i][j]==c[i-1][j-1]+1 )
        { r[++k]=a[i]; i--; j--; }
        else if (c[i][j]==c[i-1][j] ) i--;
            else j--;
    }
}

int main()
{
    ifstream f1("cmlsc.in");
    ofstream f2("cmlsc.out");
    f1>>n>>m;
    for (i=1; i<=n; i++)
        f1>>a[i];
    for (i=1; i<=m; i++)
        f1>>b[i];

    pd();
    drum();

    f2<<c[n][m]<<"\n";
    for (i=c[n][m]; i>0; i-- )
        f2<<r[i]<<" ";

    f1.close();
    f2.close();
    return 0;
}
