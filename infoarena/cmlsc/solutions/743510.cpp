//#include <iostream>
#include <fstream>
using namespace std;

int main(){int m,n,u,k;
    ifstream inr ("cmlsc.in");
    ofstream our ("cmlsc.out");
    inr >> n;
    inr >> m;
    int a[n+1], b[m+1], c[n+1][m+1],d[n+1][m+1];
    for(int i=1; i<=n; i++){
            inr >> a[i];
                for(int j=0; j<=m; j++){
                        c[i][j]=0;
                        d[i][j]=0;
                        }
            }
    for(int i=1; i<=m; i++){
            c[0][i]=0;
            d[0][i]=0;
            inr >> b[i];
            }
            c[0][0]=0;
            
    for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                    u=c[i-1][j];
                    k=c[i][j-1];
                    d[i][j]=1;
                    if(u>k){k=u; d[i][j]++;}
                    if(a[i]==b[j]){
                                  c[i][j]=k+1;
                                  d[i][j]=3;
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
             if(d[u][y]==3){ r[k]=a[u]; u--; y--; k--;}
             if(d[u][y]==2){u--;}
             if(d[u][y]==1){y--;}
             }
    our << "\n";
    k=c[n][m];
    for(int i=1; i<=k; i++){
            our << r[i] << " ";
            }
    return 0;
    }
