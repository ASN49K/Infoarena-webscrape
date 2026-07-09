#include <fstream>
#include <string.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m;
int D[300][300];
int a[300], b[300], af[300], c=1;

int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
    f>>a[i];
    for(int j=1; j<=m; j++)
    f>>b[j];
    for(int i=0; i<=n; i++)
    for(int j=0; j<=m; j++)
    {
    if(i==0 || j==0) D[i][j]=0;
    else if(a[i]!=b[j]) D[i][j]=max(D[i-1][j], D[i][j-1]);
    else if(a[i]==b[j]) D[i][j]=D[i-1][j-1]+1;
    }
    int i, j;
    for(i=n, j=m; i;)
    {
    if(a[i]!=b[j]) {if(D[i-1][j]>D[i][j-1]) i--; else j--;}
    else if(a[i]==b[j]) {af[c]=a[i]; c++; i--; j--;}
    }
    g<<D[n][m];
    g<<endl;
    for(i=c-1; i>0; i--)
    g<<af[i]<<" ";
    return 0;
}
