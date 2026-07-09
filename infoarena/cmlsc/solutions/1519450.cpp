#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

int m,n,ct;
int d[1039][1030],a[1030],b[1030];

void cmlsc(int x, int y){

    for(int i=1;i<=x;++i){

        for(int j=1;j<=y;++j){

            if(a[i]==b[j]){

                d[i][j]=(1+d[i-1][j-1]);
            }
            else if(a[i]!=b[j]){

                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
}

int main(){

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);

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

    cmlsc(m,n);

    printf("%d\n", d[m][n]);

    int v[d[m][n]],mx=d[m][n];

    for(; ct;--ct){

        printf("%d ", v[ct]);
    }
}
