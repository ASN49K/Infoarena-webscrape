#include <stdio.h>
using namespace std;
int T, A, B;

int cmmdc(int a, int b){
  if (!b) return a;
  return cmmdc(b, a % b);
}

int main(void){
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &A, &B);
    printf("%d\n", cmmdc(A, B));
  }       
  
return 0;

}