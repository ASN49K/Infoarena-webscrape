#include<stdio.h>
#define MXX 1024
#define max(a, b) ((a > b) ? a : b)
using namespace std;
int i,j,h,N,M,a[MXX],b[MXX],c[MXX][MXX],d[MXX];
int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&M,&N);
    for(i=1;i<=M;i++)
        scanf("%d",&a[i]);
    for(j=1;j<=N;j++)
        scanf("%d",&b[j]);
    for(i=1;i<=M;i++){
        for(j=1;j<=N;j++){
            if(a[i]==b[j]){
                c[i][j]=c[i-1][j-1]+1;
			}
            else{
                c[i][j]=max(c[i-1][j],c[i][j-1]);
			}
        }
    }
	i=M; j=N;
    while(i>0 && j>0){
        if(a[i]==b[j]){
            d[h++]=a[i];
            i--; j--;
		}
        else{
            if(c[i-1][j]>c[i][j-1]){
                i--;
			}
            else{
                j--;
			}
        }
    }
    printf("%d\n",h);
    for(i=h-1;i>=0;i--){
        printf("%d ",d[i]);
	}
    return 0;
}
