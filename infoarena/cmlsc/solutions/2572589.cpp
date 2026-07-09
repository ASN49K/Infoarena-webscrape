//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int v[1500],f[1500],n,m,d[1500][1500];
int rec(int i,int j){
    if(d[i][j]!=-1)
        return d[i][j];
    if(i==n+1 or j==m+1){
        d[i][j]=0;
    }
    else
    if(v[i]==f[j])
        d[i][j]=rec(i+1,j+1)+1;
    else
        d[i][j]=max(rec(i+1,j),rec(i,j+1));
    return d[i][j];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int j=1;j<=m;j++){
        cin>>f[j];
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++)
            d[i][j]=-1;
    }
    cout<<rec(1,1)<<"\n";
    int ii=1,jj=1;
    while(ii<=n and jj<=m){
        if(v[ii]==f[jj]){
            cout<<v[ii]<<" ";
            ii++;
            jj++;
            continue;
        }
        if(d[ii+1][jj]>d[ii][jj+1]){
            ii++;
        }
        else
            jj++;
    }
    return 0;
}
