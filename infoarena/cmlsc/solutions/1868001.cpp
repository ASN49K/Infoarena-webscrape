#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n;
int a[1025];
int b[1025];
int c[1025][1026];
int d[1025];
int contor;

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    fin>>m>>n;
    for (int i=1;i<=m;i++) fin>>a[i];
    for (int i=1;i<=n;i++) fin>>b[i];
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i]==b[j]) {
                c[i][j]=c[i-1][j-1]+1;
            }
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }

    fout<<c[m][n]<<'\n';
    for (int i=m,j=n;i>0;) {
        if (a[i]==b[j]) {
            d[contor++]=a[i],i--,j--;
        }
        else if (c[i - 1][j] < c[i][j - 1])
            --j;
        else --i;
    }
    for (int i=contor-1;i>=0;i--) fout<<d[i]<<' ';
}
