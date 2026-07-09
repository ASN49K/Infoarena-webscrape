//#include <iostream>
#include <fstream>
using namespace std;


int main(){int m,n,u,k;
    ifstream inr ("cmlsc.in");
    ofstream our ("cmlsc.out");
    inr >> n;
    inr >> m;
    int a[n+1], b[m+1], c[n+1][m+1];
    
    for(int i=1; i<=n; i++){
            inr >> a[i];
            c[i][0]=0;
            }
            
    for(int i=1; i<=m; i++){
            c[0][i]=0;
            inr >> b[i];
            }
            c[0][0]=0;
            
    for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                    u=c[i-1][j];
                    k=c[i][j-1];
                    if(u>k){k=u;}
                    if(a[i]==b[j]){
                                  c[i][j]=c[i-1][j-1]+1;
                                  }
                    else          {
                                  c[i][j]=k;
                                  }
                    }
            }
    our << c[n][m];
    k=c[n][m];
    int y=m, r[k+1];
    u=n;
    while(k){
             if(a[u]==b[y]){ r[k]=a[u]; u--; y--; k--;}
             if(c[u-1][y] == c[u][y]) {u--;}
             if(c[u][y-1] == c[u][y]) {y--;}
             }
    our << "\n";
    k=c[n][m];
    for(int i=1; i<=k; i++){
            our << r[i] << " ";
            }
    //cin.ignore(2);
    return 0;
    }
