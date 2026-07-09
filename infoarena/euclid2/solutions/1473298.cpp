#include <cstdio>
#define IN_FILE_NAME "euclid2.in"
#define OUT_FILE_NAME "euclid2.out"
FILE *in, *out;
int N;
long long int n1, n2, aux;
int main() {
  in = fopen(IN_FILE_NAME, "r");
  out = fopen(OUT_FILE_NAME, "w");
  fscanf(in, "%d", &N);
  for (int i = 0 ; i < N ; i++) {
    fscanf (in, "%lld %lld", &n1, &n2);
    do {
      aux = n2 % n1;
      n2 = n1;
      n1 = aux;
    } while(aux) ;
    fprintf(out, "%lld\n", n2);
  }
  return 0;
}
