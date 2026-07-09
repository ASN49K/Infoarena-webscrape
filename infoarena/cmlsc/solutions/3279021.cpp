#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1025],b[1025],x[1025][1025],xf,yf,maxi;
int main() {
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    for(int i=1;i<=m;i++){
        fin>>b[i];
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(a[i]==b[j]){
                x[i][j]=1+x[i+1][j+1];
            }
            else{
                x[i][j]=max(x[i+1][j],x[i][j+1]);
            }
        }
    }
    fout<<x[1][1]<<'\n';
    int l=x[1][1];
    int x1=1;
    int y1=1;
    while(l) {
        maxi=-1;
        for (int i = x1; i <= n; i++) {
            for (int j = y1; j <= m; j++) {
                if(a[i]==b[j] && x[i][j]==l){
                    if(a[i]>maxi){
                        maxi=a[i];
                        xf=i;
                        yf=j;
                    }
                }
            }
        }
        l--;
        x1=xf+1;
        y1=yf+1;
        fout<<maxi<<" ";
    }
    return 0;
}
