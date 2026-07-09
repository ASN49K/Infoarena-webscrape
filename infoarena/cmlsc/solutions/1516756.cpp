#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,ct,h,i,j;
int a[1000],b[1000], s[1000][1000], v[1000];

int main(){
    fin>>n>>m;
    for( i=1;i<=n;++i) fin>>a[i];
    for( i=1;i<=m;++i) fin>>b[i];
    for(i=1;i<=n;++i)
    for( j=1;j<=m;++j){
        if(a[i]==b[j]) s[i][j]=s[i-1][j-1]+1;
        else s[i][j]=max(s[i-1][j],s[i][j-1]);
    }
     i=n;
     j=m;
    while(s[i][j]>0){
        while(s[i][j]==s[i-1][j]) --i;
        while(s[i][j]==s[i][j-1]) --j;
        v[++ct]=a[i];
        --i;
        --j;
    }
    fout<<s[n][m]<<'\n';
    for( h=ct;h>=1;--h) fout<<v[h]<<' ';

    return 0;
}
