#include<fstream>
using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int n,m,d[2000][2000],a[2000],b[2000],k,sol[2000];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i){
        f>>a[i];
    }
    for(int i=1;i<=m;++i){
        f>>b[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i]==b[j]){
                d[i][j]=max(d[i-1][j],d[i][j-1])+1;
            }
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    g<<d[n][m]<<'\n';
    int i=n;
    int j=m;
    while(i&&j){
        if(a[i]==b[j]){
            sol[++k]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]>d[i][j-1]) i--;
        else j--;
    }
    for(int i=k;i>=1;--i) g<<sol[i]<<" ";
    return 0;
}
