#include<cstdio>
#include<algorithm>

using namespace std;

int V[1030][1030];
int a[1030];
int b[1030];
int N,M;
int main(){

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&N,&M);

    for(int i = 1; i <= N; ++i){
        scanf("%d ",&a[i]);
    }

    for(int j = 1; j <= M; ++j){
        scanf("%d ",&b[j]);
    }

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(a[i]==b[j]){
                V[i][j] = max(V[i-1][j-1]+1,max(V[i-1][j],V[i][j-1]));
            }
            else
                V[i][j] = max(V[i-1][j],V[i][j-1]);
        }
    }

    printf("%d\n",V[N][M]);

    for(int i = 1; i <= N; ++i){
        while(i<=N && V[i][M]==V[i-1][M]) ++i;
        if(V[i][M] == 0)
            break;
        printf("%d ",a[i]);
    }
    return 0;
}
