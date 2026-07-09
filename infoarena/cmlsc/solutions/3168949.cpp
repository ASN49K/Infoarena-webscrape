#include <fstream>
using namespace  std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1030],n,m,b[1030],maxl, dp[1025][1025];
void longest_subarray(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m];
}

void afisare_lung_MAXIMA(){
 int ri=dp[n][m],i=n,j=m,rp[1025];
 while(i>0 || j>0){
     if(a[i]==b[j]){
         rp[ri]==a[i];
         ri--;
         j--;
         i--;
     } else{
         if(dp[i-1][j]>dp[i][j-1])
             i--;
         else
             j--;
     }
 }
 for(int il=1;il<=dp[n][m];il++)
     cout<<rp[il]<<" ";
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    longest_subarray();
    cout<<endl;
    afisare_lung_MAXIMA();
    return 0;
}
