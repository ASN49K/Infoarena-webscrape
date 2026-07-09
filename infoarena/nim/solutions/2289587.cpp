#include <stdio.h>

const int TMAX = 105;
const int NMAX = 100005;

int N, T;

int vec[NMAX];

int main() {
   freopen("nim.in",  "r", stdin);
   freopen("nim.out", "w", stdout);

   scanf("%d", &T);

   for (int i = 0; i < T; ++i) {
      scanf("%d", &N);

      int xor_sum = 0;
      for (int j = 0; j < N; ++j) {
         int val;
         scanf("%d", &val);
         xor_sum ^= val;
      }
      if (xor_sum != 0) {
         printf("DA\n");
      } else {
         printf("NU\n");
      }
   }

   fclose(stdin);
   fclose(stdout);
   return 0;
}
