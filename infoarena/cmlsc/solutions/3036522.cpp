#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main() {
    int n, m, i, j;
    in>>n>>m;
    int a[n], b[m];
    for(i=0; i<n; i++)in>>a[i];
    for(i=0; i<m; i++)in>>b[i];
    
    int c[n+1][m+1];
    for(i=0; i<m+1; i++)c[0][i]=0;
    for(i=0; i<n+1; i++)c[i][0]=0;
    
    for(i = 0; i<n; i++){
        for(j=0; j<m; j++){
            if(a[i] == b[j]){
                c[i+1][j+1] = c[i][j] +1;
            } else {
                if(c[i][j+1]>c[i+1][j]){
                    c[i+1][j+1] =c[i][j+1];
                } else {
                    c[i+1][j+1] = c[i+1][j];
                }
            }
        }
    }
    int cmax = 0;
    out<<c[n+1][m+1]<<'\n';
    for(i=1; i<n+1; i++){
        for(j=1; j<m+1; j++){
            if(c[i][j]>cmax){
                out<<a[i-1]<<' ';
                cmax++;
            }
        }
    }
    return 0;
}


