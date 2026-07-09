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
    int l = c[n][m];
    int r[l]; i = n; j = m;
    while(l>0){
        if(a[i-1] == b[j-1]){
            r[--l] = a[i-1];
            i--; j--;
        } else {
            if(c[i-1][j]>c[i][j-1]){
                i--;
            } else{
                j--;
            }
        }
    }
    l = c[n][m];
    out<<l<<'\n';
    for(i=0; i<l; i++)out<<r[i]<<' ';
    return 0;
}


