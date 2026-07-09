#include <iostream>
#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define MAX_N 1024
#define MAX_M 1024
using namespace std;
int a[MAX_M+1],b[MAX_N+1];
int dyn[MAX_M+1][MAX_N+1];
int rez,m,n;

int main(void){
        freopen(FIN,"rt",stdin);
        freopen(FOUT,"wt",stdout);
        scanf("%d%d",&m,&n);
        for (int i=1;i<=m;i++){scanf("%d",&a[i]);}
        for (int i=1;i<=n;i++){scanf("%d",&b[i]);}
        rez=0;
        for (int i=1;i<=m;i++){
                for (int j=1;j<=n;j++){
                        if (a[i]==b[j]){
                                dyn[i][j]=dyn[i-1][j-1]+1;
                                rez=max(rez,dyn[i][j]);
                        } else {
                                dyn[i][j]=max(dyn[i-1][j],dyn[i][j-1]);
                        }
                }
        }
        printf("%d\n",rez);
        fclose(stdin);
        fclose(stdout);
}
