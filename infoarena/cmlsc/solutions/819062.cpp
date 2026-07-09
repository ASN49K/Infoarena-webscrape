#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int debug = 0;

int max(int a, int b) {
   return (a > b ? a : b);
}

void printVector(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		printf("%d ", *it);
	}
	printf("\n");
}

vector<int> *longestSubseq(vector<int> &A, vector<int> &B) {
   A.insert(A.begin(), 0);
   B.insert(B.begin(), 0);
   int M = A.size() - 1, N = B.size() - 1;
   int NMax = max(M, N) + 2;
   /*printf("%d %d %d\n\n", M, N, NMax);
   for (i = 0; i < M; ++i)
      printf("%d ", A[i]);
   printf("\n\n");
   for (i = 0; i < N; ++i)
      printf("%d ", B[i]);
   printf("\n\n");*/
   vector<int> *result = new vector<int>;
   int D[NMax][NMax];
   memset(D, 0, sizeof(int) * NMax * NMax);

   for (int i = 1; i <= M; ++i)
      for (int j = 1; j <= N; ++j)
         if (A[i] == B[j]) {
            if (debug) {printf("A[%d] == B[%d]\n", i, j);}
            D[i][j] = 1 + D[i-1][j-1];
         } else {
            D[i][j] = max(D[i-1][j], D[i][j-1]);
         }
   if (debug) {
      printf("A: "); printVector(A);
      printf("B: "); printVector(B);
      for (int i = 0; i <= M; ++i) {
         for (int j = 0; j <= N; ++j) {
            printf("%d ", D[i][j]);
         }
         printf("\n");
      }
   }

   //printf("M=%d, N=%d, A[M]=%d, B[N]=%d, D[M][N]=%d\n", M, N, A[M], B[N], D[M][N]);
   for (int i = M, j = N; i; ) {
      if (debug) {printf("i=%d, j=%d, A[i]=%d, B[j]=%d, D[i][j]=%d", i, j, A[i], B[j], D[i][j]);}
      if (A[i] == B[j]) {
         if (debug) {printf("\tA[i] == B[j]");}
         result->push_back(A[i]);
         --i;
         --j;
      } else if (D[i-1][j] < D[i][j-1]) {
         --j;
      } else {
         --i;
      }
      if (debug) {printf("\n");}
   }

   reverse(result->begin(), result->end());
   if (debug) {printf("result: "); printVector(*result);}
   return result;
}

int main() {
   int M, N, tmp;

   //freopen("cmlsc.in", "r", stdin);
   //freopen("cmlsc.out", "w", stdout);

   vector<int> A, B;
   scanf("%d %d", &M, &N);
   for (int i = 1; i <= M; ++i) {
      scanf("%d", &tmp);
      A.push_back(tmp);
   }
   for (int i = 1; i <= N; ++i) {
      scanf("%d", &tmp);
      B.push_back(tmp);
   }

   vector<int> *subseq = longestSubseq(A, B);

   printf("%d\n", (int)subseq->size());
   for (int i = 0, size = subseq->size(); i < size; ++i) {
      printf("%d ", (*subseq)[i]);
   }
   printf("\n");
}
