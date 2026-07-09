#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

#ifdef INFOARENA
#define ProblemName "nim"
#endif

#define MCONCAT(A, B) A B
#ifdef ProblemName
#define InFile MCONCAT(ProblemName, ".in")
#define OuFile MCONCAT(ProblemName, ".out")
#else
#define InFile "fis.in"
#define OuFile "fis.out"
#endif

int main() {
	assert(freopen(InFile, "r", stdin));
	assert(freopen(OuFile, "w", stdout));
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		int S = 0;
		while (N--) {
			int aux;
			scanf("%d", &aux);
			S ^= aux;
		}
		puts(S ? "DA" : "NU");
	}
	return 0;
}