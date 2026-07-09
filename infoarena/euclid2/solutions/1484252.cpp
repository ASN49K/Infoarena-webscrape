#include <cstdio>

using namespace std;
int i, n, m, rest;
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &i);

    while(i--){
        scanf("%d%d",&n,&m);
        while(m){
            rest=n%m;
            n=m;
            m=rest;
        }
        printf("%d\n", &n);
    }
    return 0;
}
