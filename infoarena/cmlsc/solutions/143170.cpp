#include <iostream>
#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define MAX_N 1024
#define MAX_M 1024
using namespace std;
int a[MAX_M+1],b[MAX_N+1];
int dyn[MAX_M+1][MAX_N+1];
int rez,m,n;
int sol[MAX_N+1];

int main(void){
        freopen(FIN,"rt",stdin);
        freopen(FOUT,"wt",stdout);
        scanf("%d%d",&m,&n);
        for (int i=1;i<=m;i++){scanf("%d",&a[i]);}
        for (int i=1;i<=n;i++){scanf("%d",&b[i]);}
        rez=0;
        int px,py;
        for (int i=1;i<=m;i++){
                for (int j=1;j<=n;j++){
                        if (a[i]==b[j]){
                                dyn[i][j]=dyn[i-1][j-1]+1;
                                rez=max(rez,dyn[i][j]);
                                if (rez==dyn[i][j]){
                                        px=i;
                                        py=j;
                                }
                        } else {
                                dyn[i][j]=max(dyn[i-1][j],dyn[i][j-1]);
                        }
                }
        }
        int ind=rez;
        while (ind){
                if (a[px]==b[py]){
                        sol[ind--]=a[px];
                        px--;
                        py--;
                } else if (dyn[px][py]==dyn[px-1][py]){
                        px--;} else { py--;}
        }
        printf("%d\n",rez);
        for (int i=1;i<rez;i++){
                printf("%d ",sol[i]);}
        printf("%d\n",sol[rez]);
        fclose(stdin);
        fclose(stdout);
}
