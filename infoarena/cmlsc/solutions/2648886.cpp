#include<fstream>
using namespace std;
const int LIM= 1500;
int LCS[LIM][LIM];
int solutie[LIM],n_sol;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    int x[LIM],y[LIM],nx,ny;
    f>>nx>>ny;
    for(int i=1;i<=nx;i++)
        f>>x[i];
    for(int i=1;i<=ny;i++)
        f>>y[i];

    for(int i=1;i<=nx;i++)
        for(int j=1;j<=ny;j++)
               if(x[i]==y[j])
                     LCS[i][j]=1+LCS[i-1][j-1];
               else
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);

    int n=nx;
    int m=ny;
    g<<LCS[nx][ny]<<'\n';

//   g<<'\n';
//    for(int i=1;i<=nx;i++)
//    {
//        for(int j=1;j<=ny;j++)
//            g<<LCS[i][j]<<" ";
//        g<<'\n';
//
//    }
//    g<<'\n';
    while(LCS[n][m])
    {
      if(LCS[n-1][m]==LCS[n][m-1]&&LCS[n-1][m]<LCS[n][m])
      {
          solutie[++n_sol]=x[n];
          n--,m--;

      }
      else
        if(LCS[n-1][m]<LCS[n][m-1])
                       m--;
           else
            n--;

    }
    for(int i=n_sol;i>=1;i--)
        g<<solutie[i]<<" ";
}
