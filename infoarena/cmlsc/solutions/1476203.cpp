#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,ct;
int a[1050],b[1050], d[1050][1050], v[1050];

int main(){
    fin>>n>>m;
    for(int i=1;i<=n;++i) fin>>a[i];
    for(int i=1;i<=m;++i) fin>>b[i];
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j){
        if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
        else d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    int i=n;
    int j=m;
    while(d[i][j]>0){
        while(d[i][j]==d[i-1][j]) --i;
        while(d[i][j]==d[i][j-1]) --j;
        v[++ct]=a[i];
        --i;
        --j;
    }
    fout<<d[n][m]<<'\n';
    for(int h=ct;h>=1;--h) fout<<v[h]<<' ';

    return 0;
}
