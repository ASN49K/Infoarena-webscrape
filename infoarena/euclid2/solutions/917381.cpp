

#include <stdio.h>
int n,a,b;
int cmd(int x, int y){
    int z;
    if((z=x%y)==0){
        return y;
    }
    else return cmd(x, y-z);
    
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    
    for (scanf("%d", &n); n>0; n--) {
        scanf("%d %d", &a,&b);
        printf("%d\n",cmd(a,b));
    }
    return 0;
}

