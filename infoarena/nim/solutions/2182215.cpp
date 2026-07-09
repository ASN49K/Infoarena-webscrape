#include <cstdio>

using namespace std;

int main()
{   freopen("nim.in", "r",stdin);
    freopen("nim.out", "w",stdout);
    int t,n,i,j,s,x;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        scanf("%d", &n);
        s=0;
        for(j=1; j<=n; j++){
            scanf("%d", &x);
            s^=x;
        }
        if(s==0)
            printf("NU\n");
        else
            printf("DA\n");
    }
    return 0;
}
