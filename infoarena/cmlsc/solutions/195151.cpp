/**
   LUNGIME-CMLSC( X, Y )
   1. m<-lungime[X]
   2. n<-lungime[Y]
   3. pentru i<-1, m executa
   4.        c[i,0]<-0
   5. pentru j<-0, n executa
   6.        c[0, j]<-0
   7. pentru i<-1, m executa
   8.        pentru j<-1, n executa
   9.               daca xi=yj
   10.                   c[i,j]=c[i-1][j-1]+1
   11.              altfel
   12.                    daca c[i-1, j]>=c[i, j-1]
   13.                         c[i,j]<-c[i-1, j]
   14.                    altfel
   15.                         c[i, j]<-c[i, j-1]
   16. returneaza c
   
   SCRIE-CMLSC( X, i, j )
   1. daca i=0 sau j=0 atunci
   2.      revenire
   3. daca c[i-1, j-1] = c[i, j]+1 atunci
   4.      SCRIE-CMLSC( X, i-1, j-1 )
   5.      tipareste xi
   6. altfel daca c[i, j] = c[i-1, j]
   7.      SCRIE-CMLSC( X, i-1, j )
   8. altfel
   9.      SCRIE-CMLSC( X, i, j-1 )
**/
#include <fstream>
#include <string>
#define NMax 100
using namespace std;
int c[NMax][NMax];
//int c1[NMax], c2[NMax];
int X[NMax], Y[NMax];
int m, n;

ofstream fout("cmlsc.out");

void lungime( int *X, int *Y )
{
     unsigned i, j;
     for( i=1; i<=m; i++ )
          c[i][0] = 0;
     for( j=0; j<=n; j++ )
          c[0][j] = 0;
     for( i=1; i<=m; i++ )
          for( j=1; j<=n; j++ )
               if( X[i]==Y[j] )
                   c[i][j] = c[i-1][j-1] + 1;
               else
                   if( c[i-1][j] >= c[i][j-1] )
                       c[i][j] = c[i-1][j];
                   else
                       c[i][j] = c[i][j-1];
}
/*
  Functia urmatoare e geniala pt. ca foloseste doar 2 vectori de lungime n, pt. a face treaba matricii c[n][n]
  in a calcula lungimea CMLSC

int lung( char *X, char *Y )
{
    unsigned m = strlen( X );
    unsigned n = strlen( Y );
    unsigned i, j;
    c1[0]=c2[0]=0;
    for( i=1; i<=m; i++ )
    {
         for( j=1; j<=n; j++ )
         {
              if( X[i] == Y[j] )
                  c2[j] = c1[j-1]+1;
              else if( c1[j] >= c2[j-1] )
                   c2[j] = c1[j];
              else
                   c2[j] = c1[j-1];
         }
         for( j=1; j<=n; j++ )
              c1[j] = c2[j];
    }
    return c1[n];
}
*/
void printCMLSC( int *X, int i, int j )
{
     if( i==0 || j==0 )
         return;
     if( c[i-1][j-1] = c[i][j]+1 )
     {
         printCMLSC( X, i-1, j-1 );
         fout << X[i] << ' ';
     }
     else if ( c[i-1][j] == c[i][j] )
          printCMLSC( X, i-1, j );
     else
          printCMLSC( X, i, j-1 );
}

void citire( int *X, int *Y )
{
     ifstream fin( "cmlsc.in" );
     int i;
     fin >> m;   fin >> n;
     for( i=0; i<m; i++ )
          fin >> X[i];
     for( i=0; i<n; i++ )
          fin >> Y[i];
     fin.close();
}

int main()
{
    citire( X, Y );
    lungime( X, Y );
    fout << c[m][n] << '\n';
    printCMLSC( X, m, n );
    return 0;
}
