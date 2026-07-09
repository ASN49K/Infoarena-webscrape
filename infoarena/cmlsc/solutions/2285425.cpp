#include <iostream>
#include <fstream>
using namespace std;

ofstream fo("cmlsc.out");
ifstream fi("cmlsc.in");

int a[1100],b[1100],n,m,dp[1100][1100],sol[1100],nrElem;

int main()
{
    fi>>n>>m;
    for(int i=1;i<=n;i++)fi>>a[i];
    for(int i=1;i<=m;i++)fi>>b[i];

    for(int i=1;i<=n;i++)///  pana la al i-lea element din a
        for(int j=1;j<=m;j++) /// pana la al j-lea element din b
    {
        if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1; /// se adauga un element la solutia precedenta
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }

        fo<<dp[n][m]<<"\n";


    while(dp[n][m]!=0)
    {
        if(a[n]==b[m])
        {
            nrElem++;
            sol[nrElem]=a[n];
            n--;
            m--;
        }

        else
        {
            if(dp[n-1][m]>dp[n][m-1]) /// daca subsirul comun e mai mare daca scoatem daca scoatem din sir 1
            {                         /// decat daca scoatem 1 elem din sirul 2
                n--;
            }
            else
                m--;
        }
    }


    for(int s=nrElem;s>0;s--)
        fo<<sol[s]<<" ";

    fi.close();
    fo.close();
    return 0;
}
