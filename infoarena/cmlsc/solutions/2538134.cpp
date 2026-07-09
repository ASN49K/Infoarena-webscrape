#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,d[1100][1100],a[1100],b[1100];
///d[i][j]= lg max a unui subsir comun primelor i elem din a si j elem din b
void af(int x,int y){
    if(!d[x][y])return;
    if(a[x]==b[y]){
        af(x-1,y-1);
        fout<<a[x]<<" ";
        return;
    }
    if(d[x][y]==d[x-1][y])
        af(x-1,y);
    else af(x,y-1);
}
int main(){
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j]) ///elem comun nou
                d[i][j]=1+d[i-1][j-1];
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    fout<<d[n][m]<<"\n";
    af(n,m);
    return 0;
}
