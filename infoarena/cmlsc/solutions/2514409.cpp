#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m;
int lin[1025],col[1025];
int dp[1025][1025];
int sol[1025],t;

int main()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
        cin>>lin[i];
        
    for(int i=1;i<=m;i++)
        cin>>col[i];
        
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int interm=dp[i-1][j-1];
            
            if(lin[i]==col[j])
                interm++;
                
            dp[i][j]=max( max(dp[i-1][j],dp[i][j-1]) , interm );
        }
        
    int i=n,j=m;
    
    while(i>=1 && j>=1)
    {
        if(lin[i]==col[j])
        {
            sol[++t]=lin[i];
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    
    cout<<t<<'\n';
    
    for(int k=t;k>=1;k--)
        cout<<sol[k]<<' ';
    
    return 0;
}