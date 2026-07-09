#include <fstream>

#define nMax 1024

int a[nMax], b[nMax], d[nMax][nMax], i, j, n, m, sir[nMax], t;

int main(){
    using namespace std;
    ofstream out("cmlsc.out");
    ifstream in("cmlsc.in");

    in>>m>>n;
    for(i=1; i<=m ;i++)
        in>>a[i];
    for(i=1; i<=n ;i++)
        in>>b[i];

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++){
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else d[i][j]=max(d[i-1][j], d[i][j-1]);
        }

    for(i=m, j=n; i;){
        if(a[i]==b[j]){
            sir[++t]=a[i]; i--; j--;
        }
        else if(d[i][j-1]>d[i-1][j])
                j--;
             else
                i--;
    }

    out<<t<<"\n";
    for(;t;t--)
        out<<sir[t]<<" ";

    return 0;
}
