#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m;
int a[1050],b[1050];
int mt[1050][1050];
int sol[1050],nrs;
int main()
{
    f >> n >> m ;
     for ( int i = 1 ; i <= n ; i ++ )
        f >> a[i] ;
     for ( int j = 1 ; j <= m ; j ++ )
        f >> b[j];
     for ( int i = 1 ; i <= n ; i ++ )
        for ( int j = 1 ; j <= m ; j ++ )
         if ( a[i] == b[j] )
            mt[i][j]=mt[i-1][j-1]+1;
          else
            mt[i][j]=max(mt[i-1][j],mt[i][j-1]);
      int i=n,j=m;
       while(mt[i][j])
       {
           while(mt[i][j]==mt[i-1][j])
            i--;
           while(mt[i][j]==mt[i][j-1])
            j--;
           sol[++nrs]=a[i];
           i--;
           j--;
       }
    g << nrs <<'\n';
    for ( int i = nrs ; i >= 1 ; i -- )
        g << sol[i] <<" " ;
    return 0;
}
