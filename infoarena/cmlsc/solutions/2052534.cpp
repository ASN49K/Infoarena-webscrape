#include <fstream>

using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
const int nmax=1025;
int n,m,i,j,A[nmax],B[nmax],DP[nmax][nmax],SIR[nmax],rez;
int main()
{
    fi>>n>>m;
    for(i=1;i<=n;i++)
        fi>>A[i];

    for(i=1;i<=m;i++)
        fi>>B[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(A[i]==B[j])
                DP[i][j]=DP[i-1][j-1]+1;
            else
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
    fo<<DP[n][m]<<"\n";
    rez=DP[n][m];
    i=n;
    j=m;
    while(DP[i][j])
    {
        if(A[i]==B[j])
        {
            SIR[rez--]=A[i];
            i--;
            j--;
        }
        else
        {
            if(DP[i-1][j]>DP[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=1;i<=DP[n][m];i++)
        fo<<SIR[i]<<" ";
    fi.close();
    fo.close();
    return 0;
}
