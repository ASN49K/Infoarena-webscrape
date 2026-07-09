#include<stdio.h>
int T;
int a,b;
int euclid (int a, int b) {
    if (!b)
        return a;
    euclid(b, a%b);
}
int main () {

 freopen("euclid2.in", "r", stdin);
 freopen("euclid2.out", "w", stdout);

 scanf("%d", &T);

 for (; T ; T--) {
     scanf("%d %d",&a ,&b);
     printf("%d\n", euclid(a,b));
 }





}
