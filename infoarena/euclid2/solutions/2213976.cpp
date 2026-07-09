#include <cstdio>
#define max(a, b) (a>b?a:b)
#define min(a, b) (a<b?a:b)
using namespace std;
int long N, i, a, b, R, D, I;
int main()
{
    FILE *fin, *fout;
    fin=freopen("euclid2.in", "r", stdin);
    fout=freopen("euclid2.out", "w", stdout);
    scanf("%ld", &N);
    for(i=1; i<=N; i++){
        scanf("%ld%ld", &a, &b);
        D=max(a, b); I=min(a, b);
        R=D%I;
        while(R){
            D=I;
            I=R;
            R=D%I;
        }
        printf("%ld%c", I, '\n');
    }
    return 0;
}
