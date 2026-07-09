#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int N,M,A[1030],B[1030],DP[1030][1030],Sol[1030],ind=1;
void Read()
{
    int i;
    f>>M>>N;
    for(i=1;i<=M;i++)
        f>>A[i];
    for(i=1;i<=N;i++)
        f>>B[i];
}
void Solve()
{
    int i,j;
    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
        {
            if(A[i]==B[j])
                DP[i][j]=DP[i-1][j-1]+1;
            else
                DP[i][j]=max(DP[i][j-1],DP[i-1][j]);
        }
    g<<DP[M][N]<<"\n";
    i=M;j=N;
    while(DP[i][j]!=0)
    {
        if(A[i]==B[j])
            Sol[ind++]=A[i],i--,j--;
        else
        {
            if(DP[i][j-1]>DP[i-1][j])
                j--;
            else
                i--;
        }
    }
    for(i=ind-1;i>=1;i--)
        g<<Sol[i]<<" ";
    g<<"\n";
}
int main()
{
    Read();
    Solve();
    return 0;
}
