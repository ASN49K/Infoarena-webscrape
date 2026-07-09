#include <fstream>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n,m,a[1030],b[1030],p[1030][1030],i,j;
void find(int i, int j){
    if(i<=0&&j<=0) return;
    if(a[i]==b[j]) {
        find(i-1,j-1);
        g<<a[i]<<' ';
    }
    else{
        if(p[i-1][j]>p[i][j-1])
            find(i-1,j);
        else
            find(i,j-1);
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(i=1;i<=m;i++) f>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]) p[i][j]=1+p[i-1][j-1];
            else p[i][j]=max(max(p[i-1][j],p[i][j-1]),p[i-1][j-1]);
        }
    }
    g<<p[n][m]<<'\n';
    find(n,m);
    return 0;
}
