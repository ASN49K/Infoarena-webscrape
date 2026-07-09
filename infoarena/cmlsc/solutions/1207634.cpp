#include <fstream>
#define for(i,x) for (i=1;i<=x;i++)
#define max(a, b) ((a > b) ? a : b)
#define NMAX 1030

using namespace std;

int n,m,a[NMAX],b[NMAX],i,j,T[NMAX][NMAX],best[NMAX],nr;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(i,n) f>>a[i];
    for(i,m) f>>b[i];
    for(i,n) for(j,m)
          if (a[i]==b[j]) T[i][j]=T[i-1][j-1]+1;
             else T[i][j]=max(T[i-1][j],T[i][j-1]);
    g<<T[n][m]<<'\n';
    while (n>0 && m>0)
     if (a[n]==b[m]) best[++nr]=a[n],n--,m--;
     else if (T[n-1][m]>T[n][m-1]) n--;
     else m--;
    for (i,nr) g<<best[nr-i+1]<<" ";
    return 0;
}
