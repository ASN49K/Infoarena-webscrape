#include <fstream>
using namespace std;
#define maxim(a,b) ((a > b) ? a : b)
#define NMax 1024
#define FOR(i,a,b) for(i=a;i<=b;++i)

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[NMax],b[NMax],d[NMax][NMax],sir[NMax],bst;

int main()
{
    int i,j;
    f>>m>>n;
    FOR(i,1,m)
        f>>a[i];
    FOR(i,1,n)
        f>>b[i];
    FOR(i,1,m)
        FOR(j,1,n)
            if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
            else d[i][j]=maxim(d[i-1][j-1],d[i][j-1]);
    for(i=m,j=n;i; )
        if(a[i]==b[j]) sir[++bst]=a[i],--i,--j;
        else if(d[i-1][j]<d[i][j-1]) --j;
        else --i;
    g<<bst<<'\n';
    for(i=bst;i;--i)
        g<<sir[i]<<' ';
    return 0;
}
