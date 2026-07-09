#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025],b[1025],v[1025];
int d[1025][1025];
int main()
{
    int n,m,k=0;
    f >> m >> n;
    for(int i=1;i<=m;i++)
        f >> a[i];
    for(int i=1;i<=n;i++)
        f >> b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    }

    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(a[i] == b[j]) {
            v[++k] = a[i];
            i--;
            j--;
        }
        else if(d[i-1][j] > d[i][j-1])
            i--;
        else
            j--;
    }
    g << d[m][n] << '\n';
    for(int i=1;i<=k;i++)
        g << v[i] << ' ';
    return 0;
}
