#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
const int NMax=1024;
int m,n,a[NMax],b[NMax],d[NMax][NMax],sir[NMax],bst;
int main()
{
    f>>m>>n;
    for(int i=1;i<=m;++i) f>>a[i];
    for(int i=1;i<=m;++i) f>>b[i];
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    for(int i=m,j=n;i;)
    {
        if(a[i]==b[j])
        {
            sir[++bst]=a[i];
            --i;
            --j;
        }
        else if(d[i-1][j]<d[i][j-1]) --j;
        else --i;
    }
    g<<bst<<'\n';
    for(int i=bst;i;--i) g<<sir[i]<<' ';
    return 0;
}
