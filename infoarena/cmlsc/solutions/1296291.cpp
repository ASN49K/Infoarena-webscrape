#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m, n, i, j, a[1025], b[1025], c[1025], k=0;
int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++)f>>a[i];
    for(i=1;i<=n;i++)f>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
        if(a[i]==b[j]){
            c[++k]=a[i];
        }
    }
    for(i=1;i<=k;i++)g<<c[i]<<" ";
    return 0;
}
