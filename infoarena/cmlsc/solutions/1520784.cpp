#include<algorithm>
#include<cstdio>
using namespace std;

int m,n,ct,i,j;
int ofya[1025],d[1025][1025],a[1025],b[1025];

int main(){

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);

    for(i=1;i<=m;++i){

        scanf("%d", &a[i]);
    }

    for(i=1;i<=n;++i){

        scanf("%d", &b[i]);
    }

    for(i=1;i<=m;++i){

        for(j=1;j<=n;++j){

            if(a[i]==b[j]){

                d[i][j]=1+d[i-1][j-1];
            }
            else{

                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }

    printf("%d\n", d[m][n]);

    for(i=m;j=n;i!=0){

        if(a[i]==b[j])
            ofya[++ct]=a[i],--i,--j;
        else if(d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    }

    for(int i=ct;i>0;--i){

        printf("%d ", ofya[i]);
    }
}
