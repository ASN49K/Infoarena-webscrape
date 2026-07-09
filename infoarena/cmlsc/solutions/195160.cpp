
#include <fstream>
#define NMax 1024
#define max(a,b) ( (a > b) ? (a) : (b) )
int m, n;
int A[NMax], B[NMax], c[NMax][NMax], sir[NMax], lg;

void citire()
{
    int i;
    std::ifstream fin("cmlsc.in");
    fin >> m >> n;
    for( i=1; i<=m; i++ ) fin >> A[i];
    for( i=1; i<=n; i++ ) fin >> B[i];
    fin.close();
}
int main()
{
      std::ofstream fout("cmlsc.out");
      int i, j;
      citire();

      for( i=1; i<=m; i++ )
          for( j=1; j<=n; j++ )
               if( A[i]==B[j] )
                   c[i][j] = 1 + c[i-1][j-1];
               else
                   c[i][j] = max( c[i-1][j], c[i][j-1] );

      for( i=m, j=n; i; )
           if( A[i] == B[j] )
               sir[++lg] = A[i], --i, --j ;
           else if( c[i-1][j] < c[i][j-1] )
               --j;
           else
               --i;

      fout << lg << '\n';
      for( i=lg; i>0; --i )
           fout << sir[i] << ' ';
      fout.close();

      return 0;
}

