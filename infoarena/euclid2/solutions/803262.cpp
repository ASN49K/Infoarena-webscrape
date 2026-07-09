#include <stdio.h>
int divizor(int a, int b)
{
 if (!b) return a;
 return divizor(b,a%b);
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
