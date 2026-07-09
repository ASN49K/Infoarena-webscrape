#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1030],B[1030],M,N,DP[1030][1030],Sol[1030],k;

void Read()
{
    fin>>M>>N;
  for(int i=1;i<=M;i++)
    fin>>A[i];

  for(int i=1;i<=N;i++)
    fin>>B[i];
}

void Solve()
{
   for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(A[i]==B[j])
                {
                    DP[i][j]=1+DP[i-1][j-1];
                }
            else
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
        }
    }

   int i=M,j=N;

   while ((i>0)&&(j>0))
      {
         if(A[i]==B[j])
           {
             ++k;
             Sol[k]=A[i];
             --i; --j;
           }
         else
           {
             if(DP[i-1][j]>DP[i][j-1])
                {
                  --i;
                }
             else --j;
           }
    }
}

void Print()
{
    fout<<DP[M][N]<<"\n";
  for(int i=k;i>=1;i--)
     fout<<Sol[i]<<" ";
}
int main()
{
    Read();
    Solve();
    Print();
    return 0;
}
