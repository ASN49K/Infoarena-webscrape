#include<fstream>
using namespace std;
int n, m, k, sol[1300], nrsol, i, j, a[1300], b[1300], d[1300][1300];
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main(){
    in>>n>>m;
    for(i=1; i<=n; i++)
        in>>a[i];
    for(j=1; j<=m; j++)
        in>>b[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++){
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
        }
    out<<d[n][m]<<"\n";
    i=n; j=m;
    k=d[n][m];
    while(k!=0){
        if(a[i]==b[j]){
            sol[++nrsol]=a[i];
            i--;
            j--;
            k--;
            continue;
        }
        if(d[i-1][j]>d[i][j-1])
            i--;
        else
            j--;

    }
    for(i=d[n][m]; i>=1; i--)
        out<<sol[i]<<" ";
return 0;
}
