#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short A[1025],B[1025];
short dp[1025][1025];
inline short maxi(short a,short b)
{
    if(a<b) return b;
    return a;
}
inline void rezolva(int a,int b)
{
    if(dp[a][b])
    {
        if(A[a]==B[b])
        {
            rezolva(a-1,b-1);
            fout<<A[a]<<" ";
        }
    else
    {
    if(dp[a][b]==dp[a-1][b]) rezolva(a-1,b);
    else rezolva(a,b-1);
    }
    }
}
int main()
{
    int a,b,i,j;
    fin>>a>>b;
    for(i=1;i<=a;i++) fin>>A[i];
    for(i=1;i<=b;i++) fin>>B[i];
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=b;j++)
        {
            if(A[i]==B[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=maxi(dp[i-1][j],dp[i][j-1]);
        }
    }
    fout<<dp[a][b]<<"\n";
    rezolva(a,b);
}
