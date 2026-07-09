#include <cstdio>
using namespace std;
int n, a, x, t, i;
int main(){
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    scanf("%d", &t);
    for(;t;t--)
    {
        scanf("%d", &n);
        x=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d", &a);
            x=x^a;
        }
        if(x==0)
            printf("NU\n");
        else
            printf("DA\n");
    }
    return 0;
}
