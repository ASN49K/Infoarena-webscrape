#include<cstdio>
#include<algorithm>
using namespace std;
int C[1100][1100],a[1100],b[1100],Sol[1100],N,M,k;
inline void BackTrack(int x,int y)
{
    if (k==0) return;
    if (a[x]==b[y])
        {
            Sol[k--]=a[x];
            BackTrack(x-1,y-1);
        }
        else
            {
                if (C[x-1][y]>C[x][y-1]) BackTrack(x-1,y);
                        else BackTrack(x,y-1);
            }
}
inline void Write_Sol(int N,int M)
{
    printf("%d\n",C[N][M]);
    k=C[N][M];
    BackTrack(N,M);
    for (int i=1;i<=C[N][M];++i)
        printf("%d ",Sol[i]);
    printf("\n");
}
inline void Solve(int N,int M)
{
    for (int i=1;i<=N;++i)
        for (int j=1;j<=M;++j)
            if (a[i]==b[j]) C[i][j]=C[i-1][j-1]+1;
                    else C[i][j]=max(C[i][j-1],C[i-1][j]);
}
inline void Load_Data(int &N,int &M)
{
    scanf("%d%d",&N,&M), C[0][0]=0;
    for (int i=1;i<=N;++i)
        scanf("%d",&a[i]), C[i][0]=0;
    for (int i=1;i<=M;++i)
        scanf("%d",&b[i]), C[0][i]=0;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    Load_Data(N,M);
    Solve(N,M);
    Write_Sol(N,M);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
