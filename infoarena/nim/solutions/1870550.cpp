#include <cstdio>
using namespace std;

int t, x;
int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    scanf("%d", &t);
    for(int i = 1; i <= t ; ++i){
        int XOR = 0, n, x;
        scanf("%d", &n);
        for(int i = 1; i <= n ; ++i){
            scanf("%d", &x);
            XOR = XOR ^ x;
        }
        if(XOR) printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}
