#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>* longestSubseq(vector<int> A, vector<int> B) {
   A.insert(A.begin(), 0);
   B.insert(B.begin(), 0);
   int M = A.size(), N = B.size();
   vector<int> *result = new vector<int>;
   vector< vector<int> > D(M, vector<int>(N, 0));

   for (int i = 1; i < M; ++i)
      for (int j = 1; j < N; ++j) {
         if (A[i] == B[j]) {
            D[i][j] = 1 + D[i-1][j-1];
         } else {
            D[i][j] = max(D[i-1][j], D[i][j-1]);
         }
	  }

   for (int i = M - 1, j = N - 1; i; ) {
      if (A[i] == B[j]) {
         result->push_back(A[i]);
         --i;
         --j;
      } else if (D[i-1][j] < D[i][j-1]) {
         --j;
      } else {
         --i;
      }
   }

   reverse(result->begin(), result->end());
   return result;
}

int main() {
   int M, N, tmp;

   freopen("cmlsc.in", "r", stdin);
   freopen("cmlsc.out", "w", stdout);

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
