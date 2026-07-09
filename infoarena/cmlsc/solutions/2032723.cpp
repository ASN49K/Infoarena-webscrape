#include <iostream>
#include <fstream>
using namespace std;
int  v[1026][1026],a[1026],b[1026],sol[1026];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,i,j,m;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    for(i=0;i<=n;i++){
        v[i][0]=0;
    }
    for(i=0;i<=m;i++){
        v[0][m]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]){
                v[i][j]=v[i-1][j-1]+1;
            }
            else{
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    cout<<v[n][m]<<'\n';
    int ind1=n,ind2=m,cnt=0;
    while(v[ind1][ind2]!=0){
        if(a[ind1]==b[ind2]){
           sol[++cnt]=a[ind1];
           ind1--;
           ind2--;
        }
        else{
           if(v[ind1-1][ind2]>v[ind1][ind2-1]){
              ind1--;
           }
           else
              ind2--;
        }
    }
    for(i=cnt;i>=1;i--)
        cout<<sol[i]<<" ";
    return 0;
}
