#include <cstdio>

#define max(a,b) ((a > b) ? a : b )

using namespace std;

int n,m;
int a[1025],b[1025],x[1025][1025];
int best[1025],nrel;

void citire(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&b[i]);
}

void matrice(){
    int maxim=0;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j){
            if(a[i]==b[j])
                x[i][j]=x[i-1][j-1]+1;
            else
                x[i][j]=max(x[i-1][j],x[i][j-1]);
            if(x[i][j]>maxim)
                    maxim=x[i][j];
        }
    for(int i=m,j=n;x[i][j]!=0;){
        if(a[i]==b[j]){
            best[++nrel]=b[j];
            i--;
            j--;
        }
        else
            if(x[i-1][j]>x[i][j-1])
                i--;
            else
                j--;
    }
    printf("%d\n",maxim);
    for(int i=nrel;i>=1;i--)
        printf("%d ",best[i]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    matrice();
    return 0;
}
