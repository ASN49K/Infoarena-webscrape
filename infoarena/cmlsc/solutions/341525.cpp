#include <iostream>
#include <fstream>

using namespace std;

#define fin  "cmlsc.in"
#define fout "cmlsc.out"

#define NMAX 1050

int N, M, dp[NMAX][NMAX];
int s1[NMAX], s2[NMAX];

void ReadData()
{
     ifstream f(fin);
     
     f >> N >> M;
     
     for ( int i = 1; i <= N; ++i )
         f >> s1[i];
     for ( int i = 1; i <= M; ++i )
         f >> s2[i];
  
     f.close();     
}

void Solve()
{
     for ( int i = 1; i <= N; ++i )
     for ( int j = 1; j <= M; ++j )
         if ( s1[i] == s2[j] )
             dp[i][j] = dp[i-1][j-1] + 1;
         else
             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
}

void trace(int i, int j, ofstream &f)
{
     if ( i == 0 || j == 0 )
        return ;
   
     if ( s1[i] == s2[j] )
     {
          trace(i-1,j-1,f);
          f << s1[i] << " ";   
     }
     else
     {
          if ( dp[i-1][j] > dp[i][j-1] )
               trace(i-1,j,f);
          else
               trace(i,j-1,f);
     }
}

void PrintSol()
{
     ofstream f(fout);
     
     f << dp[N][M] << endl;
     trace(N,M,f);
     
     f.close();
}

int main()
{
    ReadData();
    Solve();
    PrintSol();
    return 0;    
}
