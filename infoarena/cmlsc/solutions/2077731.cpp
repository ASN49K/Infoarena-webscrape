#include <fstream>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
const int nm=1024;
int dp[nm+5][nm+5],n,m,v1[nm+5],v2[nm+5];
vector<int>sl;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v1[i];
    for(int i=1;i<=m;i++)
        cin>>v2[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(v1[i]==v2[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    cout<<dp[n][m]<<"\n";
    int pn=n,pm=m;
    while(pn and pm)
    {
        if(v1[pn]==v2[pm])
        {
            sl.push_back(v1[pn]);
            pn--;
            pm--;
            continue;
        }
        if(dp[pn-1][pm]==dp[pn][pm])
            pn--;
        else
            pm--;
    }
    for(int i=sl.size()-1;i>=0;i--)
        cout<<sl[i]<<" ";
    return 0;
}
