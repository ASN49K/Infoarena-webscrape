#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int max(int a, int b) {
   return (a > b ? a : b);
}

vector<int> *longestSubseq(const vector<int> &A, const vector<int> &B) {
   int i, j, M = A.size(), N = B.size();
   int NMax = max(M, N) + 2;
   vector<int> *result = new vector<int>;
   int D[NMax][NMax];
   memset(D, 0, sizeof(int) * NMax * NMax);

    for (i = 1; i <= M; ++i)
       for (j = 1; j <= N; ++j)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);

    for (i = M, j = N; i; )
        if (A[i] == B[j]) {
            result->push_back(A[i]);
            --i;
            --j;
        }
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

   return result;
}

int main() {
    int M, N, i, tmp;
    
    //freopen("cmlsc.in", "r", stdin);
    //freopen("cmlsc.out", "w", stdout);

    vector<int> A, B;
    scanf("%d %d", &M, &N);
    A.push_back(0);
    B.push_back(0);
    for (i = 1; i <= M; ++i) {
        scanf("%d", &tmp);
        A.push_back(tmp);
    }
    for (i = 1; i <= N; ++i) {
        scanf("%d", &tmp);
        B.push_back(tmp);
    }

    vector<int> *subseq = longestSubseq(A, B);

    printf("%d\n", subseq->size() - 1);
    for (i = subseq->size() - 1; i; --i) {
       printf("%d ", (*subseq)[i]);
    }
    printf("\n");
}
