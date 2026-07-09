#include <fstream>
#define NMax 1024

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int M, N, a[NMax], b[NMax], Dp[NMax][NMax], sir[NMax], bst;

 int maxim(int x,int y)
 {
     if(x>y)
        return x;
    return y;
 }

int main()
{
    int i, j;
    f>>M>>N;
    for(i=1;i<=M;i++)
        f>>a[i];
    for(i=1;i<=N;i++)
        f>>b[i];
    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
            if (a[i] == b[j])
                Dp[i][j] = 1 + Dp[i-1][j-1];
            else
                Dp[i][j] = maxim(Dp[i-1][j], Dp[i][j-1]);
    i=M;
    j=N;
    while(i)
        if (a[i] == b[j])
            sir[++bst] = a[i], i--,j--;
        else
            if (Dp[i-1][j] < Dp[i][j-1])
                j--;
            else
                i--;
    g<<bst<<"\n";
    for (i = bst; i; --i)
        g<<sir[i]<<" ";
    return 0;
}
