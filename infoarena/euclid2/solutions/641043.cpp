#include <cstdio>

using namespace std;
int cmmdc(int a, int b) {
    if(b == 0) return a;
    return cmmdc(b, a % b);
}
int main()
{
    int tc;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&tc);
    while(tc) {
        int n,m;
        scanf("%d %d",&n, &m);
        printf("%d\n",cmmdc(n,m));
        tc--;
    }
    return 0;
}
