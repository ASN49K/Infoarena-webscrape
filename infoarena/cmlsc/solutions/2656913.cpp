//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int v[1050],f[1050],d[1050][1050],ans[1050],cont=0;
void func(int i,int j){
    if(d[i][j]==0)
        return;
    if(v[i]==f[j]){
        //cout<<v[i];
        ans[++cont]=v[i];
        func(i-1,j-1);
    }
    else{
        if(d[i-1][j]>d[i][j-1])
            func(i-1,j);
        else
            func(i,j-1);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=m;i++){
        cin>>f[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            d[i][j]=max(d[i-1][j],d[i][j-1]);
            if(v[i]==f[j]){
                d[i][j]=max(d[i][j],d[i-1][j-1]+1);
            }
        }
    }
    cout<<d[n][m]<<"\n";
    func(n,m);
    for(int i=cont;i>=1;i--)
        cout<<ans[i]<<" ";
    return 0;
}
