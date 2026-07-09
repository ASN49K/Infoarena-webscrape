#include<cstdio>

int cmmdc(int a, int b) {
  if(a % b == 0)
    return b;
  if(b % a == 0)
    return a;
  if(a > b) {
    cmmdc(a, a % b);
    cmmdc(b, a % b);
  }
  else {
    cmmdc(b, b % a);
    cmmdc(a, b % a);
  }

}

int main() {

  FILE* in = fopen("euclid2.in", "r");
  FILE* out = fopen("euclid2.out", "w");
  int a, b;

  fscanf(in, "%d%d", &a, &b);
  int c = cmmdc(a, b);
  fprintf(out, "%d\n", c);
  //fprintf(stdout, "%d\n", c);

  return 0;
}
