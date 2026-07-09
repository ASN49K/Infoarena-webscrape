#include<iostream>
#include<fstream>
int d[1025][1025],a[1025],b[1025],v[1025];
using namespace std;
int main(){
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    long long int n,m,k=0,x,y;
    for(long long int i=1;i<=1025;i++){
        d[0][i]=0;
        d[i][0]=0;
    }
    in>>n>>m;
    for(long long int i=1;i<=n;i++){
        in>>a[i];
    }
    for(long long int i=1;i<=m;i++){
        in>>b[i];
    }
    for(long long int i=1;i<=n;i++){
        for(long long int j=1;j<=m;j++){
            if(a[i]==b[j]){
                d[i][j]=d[i-1][j-1]+1;
            }else{
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    x=m;
    y=n;
    for(long long int i=d[n][m];i>0;i--){
        while(d[y][x]==i){
            x--;
        }
        x++;
        while(d[y][x]==i){
            y--;
        }
        y++;
        v[i]=b[x];
        y--;
        x--;
    }
    out<<d[n][m]<<'\n';
    for(long long int i=1;i<=d[n][m];i++){
        out<<v[i]<<" ";
    }
}
