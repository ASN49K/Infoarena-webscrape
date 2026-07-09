#include <cstdio>

using namespace std;

int t,a,b,r;

int main(){
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    for(scanf("%d", &t); t; --t){
        scanf("%d %d", &a, &b);
        r = 0;
        while(b){
            r = a % b;
            a = b;
            b = r;
        }
        printf("%d\n", a);
    }
    return 0;
}
