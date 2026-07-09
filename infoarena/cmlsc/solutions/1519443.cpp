#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

int m,n,ct;

int main(){

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);

    int d[m+1][n+1],a[m+1],b[n+1];

    d[0][0]=0;
    a[0]=0;
    b[0]=0;

    for(int i=1;i<=m;++i){

        d[i][0]=0;
        scanf("%d", &a[i]);
    }

    for(int i=1;i<=n;++i){

        d[0][i]=0;
        scanf("%d", &b[i]);
    }

    for(int i=1;i<=m;++i){

        for(int j=1;j<=n;++j){

            if(a[i]==b[j]){

                d[i][j]=(1+d[i-1][j-1]);
            }
            else if(a[i]!=b[j]){

                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }

    printf("%d\n", d[m][n]);

    int v[d[m][n]],mx=d[m][n];

    while(mx>0){

        int i=m,j=n;

        if(d[i-1][j]!=d[i][j] && d[i][j-1]!=d[i][j]){

            if(d[i][j-1]==d[i-1][j]){

                if(a[i]==b[j]){

                    v[ct]=a[i];
                    ++ct;
                    --mx;
                }
            }
        }
        if(d[i-1][j]==d[i][j-1]){

            --i;--j;
        }
        else if(d[i-1][j]>d[i][j-1]){

            --i;
        }
        else if(d[i-1][j]<d[i][j-1]){

            --j;
        }
    }

    for(; ct;--ct){

        printf("%d ", v[ct]);
    }
}
