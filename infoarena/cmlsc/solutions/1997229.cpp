#include<cstdio>
#include<algorithm>

using namespace std;

int V[1030][1030];
int a[1030];
int b[1030];
int result[1030];
int k;
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
                V[i][j] = V[i-1][j-1]+1;
            }
            else
                V[i][j] = max(V[i-1][j],V[i][j-1]);
        }
    }

    printf("%d\n",V[N][M]);

    for(int i = N, j = M; i;){
        if(a[i]==b[j]){
            result[k++] = a[i];
            --i;
            --j;
        }else if(V[i-1][j] < V[i][j-1]){
            --j;
        }else
            --i;
    }

    for(--k; k>=0; --k)
        printf("%d ",result[k]);

    return 0;
}
