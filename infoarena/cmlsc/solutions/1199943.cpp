#include<cstdio>
using namespace std;
struct mazi{int x,y;};
int a[1025];
int b[1025];
int max[1025][1025];
char e[1025][1025];
mazi pr[1025][1025];
int main(){
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    int n,m,i,j;
    scanf ("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf ("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf ("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if ((max[i-1][j]>max[i][j-1] ||e[i][j-1]!=-1) &&max[i-1][j]>max[i-1][j-1] &&e[i-1][j]==-1){
                max[i][j]=max[i-1][j];
                pr[i][j]=pr[i-1][j];
            }
            else
            if (max[i-1][j-1]<max[i][j-1] &&e[i][j-1]==-1){
                max[i][j]=max[i][j-1];
                pr[i][j]=pr[i][j-1];
            }
            else {
                max[i][j]=max[i-1][j-1];
                if (e[i-1][j-1]==-1) pr[i][j]=pr[i-1][j-1];
                else {
                    pr[i][j].x=i-1;
                    pr[i][j].y=j-1;
                }
            }

            if (a[i]==b[j]){
                max[i][j]++;
                e[i][j]=a[i];
            }
            else e[i][j]=-1;
        }

        if (e[n][m]==-1){
            i=pr[n][m].x;
            j=pr[n][m].y;
        }
        else {
            i=n;
            j=m;
        }

        printf ("%d\n",max[n][m]);
        m=1;
        while(i>0 &&j>0){
            a[m]=e[i][j];
            m++;
            n=pr[i][j].x;
            j=pr[i][j].y;
            i=n;
        }
        for(i=m-1;i>0;i--)
            printf ("%d ",a[i]);
        return 0;
}
