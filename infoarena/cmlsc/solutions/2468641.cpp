#include <cstdio>

#define MAX 1025
int m,n;
int a[MAX],b[MAX];
int dp[MAX][MAX];
int counter;
int sol[MAX];
int max(int x,int y){
        if(x>y) return x;
        else return y;
}

void dynamic(){
        for(int i=1;i<=m;++i){
                for(int j=1;j<=n;++j){
                        if(a[i]==b[j]){
                                dp[i][j] = dp[i-1][j-1]+1;
                        }
                        else{
                                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                        }
                }
        }
}

void build(){
        int i,j;
        i=m;
        j=n;
        while(i){
                if(a[i]==b[j]){
                        sol[++counter]=a[i];
                        --i;--j;
                }else	if(dp[i-1][j]<dp[i][j-1]) j--;
                else i--;
        }
}

void write(){
        printf("%d\n",counter);
        for(int i = counter;i>0;--i) printf("%d ", sol[i]);
}

void read(){

        scanf("%d %d",&m,&n);


        for(int i = 1; i<=m;++i){
                scanf("%d",&a[i]);
        }

        for(int i = 1; i<=n;++i){
                scanf("%d",&b[i]);
        }

}

int main() {
        freopen("cmlsc.in","r",stdin);
        freopen("cmlsc.out","w",stdout);

        read();
        dynamic();
        build();
        write();
        return 0;
}