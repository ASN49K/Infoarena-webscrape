#include <cstdio>
using namespace std;
int cmmdc(int a, int b){
    int r;
    while((r=a%b)){
        a = b;
        b = r;
    }
    return b;
}
int main()
{
    int t, a, b;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
    return 0;
}
