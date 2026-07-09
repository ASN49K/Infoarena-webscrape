#include <stdio.h>
#include <stdlib.h>

int sx[1026];
int sy[1026];
int lcs[1026];
int memo[1026][1026];
int m,n,i,j;

int max(int x,int y){
    if(x>=y){
        return x;
    }
    return y;
}

void printmat(){
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            printf("%d ",memo[i][j]);
        }
        printf("\n");
    }

}

int main(){
    int temp;
    int nr=0;

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++){
        scanf("%d",&sx[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d",&sy[i]);
    }

    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(sx[j]==sy[i]){
                memo[i][j]=memo[i-1][j-1]+1;
            }else{
                memo[i][j]=max(memo[i-1][j],memo[i][j-1]);
            }
        }
    }
//    printmat();
    printf("%d\n",memo[m][n]);


    i=m;
    j=n;
    nr=0;
    while(memo[i][j]){
        temp=memo[i][j];
        while(memo[i][j-1]==temp){
            j--;
        }
        while(memo[i-1][j]==temp){
            i--;
        }
        lcs[nr++]=sx[j];
        i--;
        j--;
    }

    for(i=nr-1;i>=0;i--){
        printf("%d ",lcs[i]);
    }

    return 0;
}
