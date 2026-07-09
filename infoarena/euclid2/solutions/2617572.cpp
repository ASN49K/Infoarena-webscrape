#include <stdio.h>
using namespace std;
int cmmdc(int a, int b){
  int r;
  while(b>0){
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}
int main(){
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);
  int t, i, a, b;
  scanf("%d", &t);
  for(i=0; i<t; i++){
    scanf("%d%d", &a, &b);
    printf("%d\n", cmmdc(a, b));
  }
  return 0;
}
