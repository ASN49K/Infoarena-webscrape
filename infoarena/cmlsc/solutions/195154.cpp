#include <fstream>
#define NMax 1024
#define max(a,b) ( (a > b) ? (a) : (b) )
#define FOR( i, A, B ) for( i=A; i<=B; i++ )
int m, n;
int A[NMax], B[NMax], c[NMax][NMax], sir[NMax], lg;

void citire()
{
    int i;
    std::ifstream fin("cmlsc.in");
    fin >> m >> n;
    FOR( i, 1, m ) fin >> A[i];
    FOR( i, 1, n ) fin >> B[i];
    fin.close();
}
int main()
{
      std::ofstream fout("cmlsc.out");
      int i, j;
      citire();

      FOR( i, 1, m )
          FOR( j, 1, m )
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
      FOR( i, 1, lg )
           fout << sir[i] << ' ';
      fout.close();

      return 0;
}
