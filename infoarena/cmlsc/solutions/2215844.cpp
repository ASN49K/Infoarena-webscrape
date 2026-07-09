#include <cstdio>
using namespace std;
int N, M, Sir1[1029], Sir2[1029], i, Count[1029], S, Smax, vfmax, vfsecv, V[1029];
void Solve(int vf1, int vf2, int vf, int V[1029]){
    while(vf1 && vf2 && Sir1[vf1]==Sir2[vf2]){vf++; V[vf]=Sir1[vf1]; vf1--; vf2--; }
    if(vf1 && vf2){
        Solve(vf1-1, vf2, vf, V);
        Solve(vf1, vf2-1, vf, V);
    }
    else{
        if(vf>vfmax){
            vfmax=vf;
            for(int n=1; n<=vf; n++)Count[n]=V[n];
        }
    }
}
int main()
{
    FILE *fin, *fout;
    fin=freopen("cmlsc.in", "r", stdin);
    scanf("%d%d", &N, &M);
    for(i=1; i<=N; i++)scanf("%d", &Sir1[i]);
    for(i=1; i<=M; i++)scanf("%d", &Sir2[i]);
    fclose(fin);
    Solve(N, M, 0, V);
    fout=freopen("cmlsc.out", "w", stdout);
    printf("%d%c", vfmax, '\n');
    for(i=vfmax; i>=1; i--)printf("%d ", Count[i]);
    fclose(fout);
}
