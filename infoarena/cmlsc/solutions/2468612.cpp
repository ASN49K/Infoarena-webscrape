#include <cstdio>

#define MAX 1025
int m,n;
int a[MAX],b[MAX];
int dp[MAX][MAX];
int lmax;
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
        lmax = dp[m][n];
}

void build(){
        int idx = lmax;
        int i = m;
        int j = n;
        while (idx) {
                if (dp[i][j] == dp[i - 1][j - 1]+1) {
                        sol[idx] = a[i];
                        --idx;
                        --i;
                        --j;
                        continue;
                }
                if (dp[i][j] == dp[i - 1][j]) {
                        --i;
                }else if (dp[i][j] == dp[i][j - 1]) {
                        --j;
                }
        }
}

void write(){
        printf("%d\n",lmax);
        for(int i = 1;i<=lmax;++i) printf("%d ", sol[i]);
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