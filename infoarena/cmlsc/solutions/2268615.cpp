#include<fstream>
using namespace std;
#define maxim(a, b) ((a > b) ? a : b)
int d[1025][1025], sir[1025], a[1025], b[1025], k;
void construieste(int i, int j){
    if(i&&j){
        if(a[i]==b[j]){
            construieste(i-1,j-1);
            sir[++k]=a[i];
        }
        else if(d[i-1][j]>d[i][j-1])
            construieste(i-1,j);
        else
            construieste(i,j-1);
    }
}
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int i,j,m,n;
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(j=1;j<=n;j++)
        f>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
    construieste(m,n);
    g<<k<<"\n";
    for(i=1;i<=k;i++)
        g<<sir[i]<<" ";
}
