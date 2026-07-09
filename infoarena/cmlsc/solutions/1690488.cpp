#include <fstream>
#include <cmath>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int N,M,dp[1030][1030],a[1030], b[1030],rs[1030],o;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    
     for(int i=1; i<=N; ++i)
             cin>>a[i];
     for(int i=1; i<=M; ++i)
             cin>>b[i];
                    
     for(int i=1; i<=N; ++i)
       for(int j=1; j<=M; ++j)
       {
               if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
               else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
       }
       cout<<dp[N][M]<<"\n";
       
       for(int i=N; i; )
          for(int j=M; j; )
          {
                  if(a[i]==b[j])
                  {
                                rs[++o]=a[i];
                                j--;
                                i--;
                  }
                  if(dp[i-1][j]<dp[i][j-1]) 
                  j--;
                  else
                  i--;
          }              
         
    for(int i=o; i; --i)
    cout<<rs[i]<<" ";
       
return 0;
}       
                       
    

