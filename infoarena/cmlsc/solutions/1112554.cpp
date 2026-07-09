//#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

#define NMax 1001
int i,j,n,m,q[NMax],dp[NMax][NMax],bst;
int v[NMax],c[NMax];


int main()
{
    cin>>m>>n;
    v[0]='x';
    c[0]='x';
    for(i=1;i<=m;i++){
        cin>>v[i];
    }
    for(j=1;j<=n;j++){
        cin>>c[j];
    }

    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            if(v[i]==c[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    i=m;
    j=n;
    while(i){
        if(v[i]==c[j]){
            q[++bst]=v[i];
            i--;
            j--;
        }else{
            if(dp[i-1][j]<dp[i][j-1]){
                j--;
            }else{
                i--;
            }
        }
    }
    cout<<bst<<'\n';

    for(i=bst;i>0;i--){
        cout<<q[i]<<' ';
    }
    return 0;
}
