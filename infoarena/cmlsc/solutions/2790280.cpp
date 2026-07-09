#include <fstream>

using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
int v1[1030],v2[1030],dp[1030][1030],rez[1030];
int main()
{
    int n1,n2,i,j,k;
    cin>>n1>>n2;
    for (i=1; i<=n1; i++)
        cin>>v1[i];
    for (i=1; i<=n2; i++)
        cin>>v2[i];
    for (i=1; i<=n1; i++)
        for (j=1; j<=n2; j++)
            if (v1[i]==v2[j])
                dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+1);
            else
                dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
    i=n1;
    j=n2;
    k=0;
    while (i>=1 && j>=1)
        if (v1[i]==v2[j])
        {
            k++;
            rez[k]=v1[i];
            i--;
            j--;
        }
        else
            if (dp[i][j]==dp[i][j-1])
                j--;
            else
                i--;
    cout<<dp[n1][n2]<<"\n";
    for (i=k; i>=1; i--)
        cout<<rez[i]<<" ";
    return 0;
}
