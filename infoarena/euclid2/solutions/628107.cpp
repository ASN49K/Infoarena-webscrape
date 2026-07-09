#include <stdio.h>
using namespace std;
int cmmdc(int a, int b){
if (b==0) return a;
return cmmdc(b, a % b);
}
int main(void){
int a,b,c;
freopen("euclid2.in", "r", stdin);
freopen("euclid2.out", "w", stdout);
scanf("%d", &c);
while(c--){
scanf("%d %d", &a, &b);
printf("%d\n", cmmdc(a, b));
}      
return 0;
}
