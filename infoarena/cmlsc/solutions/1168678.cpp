#include <fstream>
#define fr(i,x) for (i=1;i<=x;i++)
#define mx(a, b) ((a > b) ? a : b)
#define NMAX 1030
using namespace std;
int n,m,a[NMAX],b[NMAX],i,j,T[NMAX][NMAX],bst[NMAX],nr;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    fr(i,n) f>>a[i];
    fr(i,m) f>>b[i];
    fr(i,n) fr(j,m)
          if (a[i]==b[j]) T[i][j]=T[i-1][j-1]+1;
             else T[i][j]=mx(T[i-1][j],T[i][j-1]);
    g<<T[n][m]<<'\n';
    while (n>0 && m>0)
     if (a[n]==b[m]) bst[++nr]=a[n],n--,m--;
     else if (T[n-1][m]>T[n][m-1]) n--;
     else m--;
    fr (i,nr) g<<bst[nr-i+1]<<" ";
    f.close();
    g.close();
    return 0;
}
