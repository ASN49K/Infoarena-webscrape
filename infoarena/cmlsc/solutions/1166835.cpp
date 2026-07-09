#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int M,N,i,j;
int v1[1025],v2[1025],sol[1025],contor,a[1025][1025];

int main()
{
    f>>M>>N;
    for (i=1;i<=M;i++)
    f>>v1[i];
    for (i=1;i<=N;i++)
    f>>v2[i];
    for (i=1;i<=M;i++)
    for (j=1;j<=N;j++)
    if (v1[i]==v2[j])
    a[i][j]=a[i-1][j-1]+1;
    else a[i][j]=max(a[i-1][j],a[i][j-1]);
    for (i=M,j=N; i>0;)
    if (v1[i]==v2[j]) {contor++;sol[contor]=v1[i];j--;i--;}
    else if (a[i][j-1]>a[i-1][j]) j--;
    else i--;
    g<<contor<<'\n';
    for (i=contor;i>0;i--)
    g<<sol[i]<<' ';
    f.close();g.close();
    return 0;
}
