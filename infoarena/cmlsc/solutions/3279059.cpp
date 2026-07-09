#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1051],b[1051],n,m,DP[1050][1050],Rec[1001],ind1=1,ind2;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int j=1;j<=m;j++)
    {
        cin>>b[j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]!=b[j])
            {
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            }else
            {
                DP[i][j] = 1 + DP[i-1][j-1]; 
            }
        }
    }
    int i=n,j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            Rec[ind1] = a[i];
            i--;
            j--;
            ind1++;
        }else
        {
            if(DP[i-1][j]==DP[i][j])
            {
                i--;
            }else
            {
                j--;
            }
        }
    }
    ind1--;
    cout<<DP[n][m]<<'\n';
    for(int i=ind1;i>0;i--)
    {
        cout<<Rec[i]<<" ";
    }
    
    return 0;
}