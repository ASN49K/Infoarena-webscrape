#include <stdio.h>
int divizor(int x, int y)
{
 if (!y) return 0;
 return divizor(y,x%y);
}
int main(){
int x,y,n;
freopen("euclid2.in", "r", stdin);
freopen("euclid2.out", "w", stdout);
scanf("%d",&n);
for (; n; --n)
{
    scanf("%d %d",&x,&y);
    printf("%d\n",divizor(x,y));
}
return 0;
}
