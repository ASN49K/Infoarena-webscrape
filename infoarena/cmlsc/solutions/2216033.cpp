#include <cstdio>
#define max(a, b) (a>b?a:b)
using namespace std;
int N, M, Sir1[1029], Sir2[1029], i, j, Count[1029], Hideyoshi[1029][1029], vf;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    scanf("%d%d", &N, &M);
    for(i=1; i<=N; i++)scanf("%d", &Sir1[i]);
    for(i=1; i<=M; i++)scanf("%d", &Sir2[i]);
    for(i=1; i<=N; i++)
    for(j=1; j<=M; j++){
        if(Sir1[i]==Sir2[j])Hideyoshi[i][j]=Hideyoshi[i-1][j-1]+1;
        else Hideyoshi[i][j]=max(Hideyoshi[i-1][j], Hideyoshi[i][j-1]);
    }
    i=N; j=M;
    while(i&&j){
        if(Sir1[i]==Sir2[j]){Count[++vf]=Sir1[i]; i--; j--;}
        else if(Hideyoshi[i-1][j]>Hideyoshi[i][j-1])i--;
        else j--;
    }
    freopen("cmlsc.out", "w", stdout);
    printf("%d%c", vf, '\n');
    for(i=vf; i>=1; i--)printf("%d ", Count[i]);
    return 0;
}

