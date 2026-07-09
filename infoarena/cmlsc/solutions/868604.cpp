#include<cstdio>
using namespace std;
#define MAX 1026
int A[MAX],B[MAX],SC[MAX][MAX];
int m,n;
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
inline void write(int i,int j){
    if(i==0 || j==0)
        return ;
    if(A[i]==B[j]){
        write(i-1,j-1);
        printf("%d ",A[i]);
    }
    else{
        if(SC[i][j-1]>SC[i-1][j])
            return write(i,j-1);
        else
            return write(i-1,j);
    }
}
int main(){
    int i,j;
    freopen("cmlsc.in","r",stdin);
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++) scanf("%d",&A[i]);
    for(j=1;j<=n;j++) scanf("%d",&B[j]);
    fclose(stdin);
    for(i=0;i<=m;i++) SC[i][0]=0;
    for(j=0;j<=n;j++) SC[0][j]=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(A[i]==B[j])
                SC[i][j]=1+SC[i-1][j-1];
            else
                SC[i][j]=max(SC[i][j-1],SC[i-1][j]);
        }
    }
    freopen("cmlsc.out","w",stdout);
    printf("%d\n",SC[m][n]);
    write(m,n);
    printf("\n");
    fclose(stdout);
    return 0;
}
