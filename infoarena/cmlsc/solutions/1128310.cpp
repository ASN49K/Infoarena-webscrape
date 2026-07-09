#ifdef INFOARENA
#include "infoarena.h"
#endif

#include <fstream>
#include <algorithm>

#ifdef INFOARENA
namespace cmlsc {
#endif

unsigned const int maxN = 1024, maxM = 1024;

int main()
{
	std::ifstream in("cmlsc.in");
	std::ofstream out("cmlsc.out");
	unsigned N, M;
	unsigned short A[maxN + 1], B[maxM + 1], LCS[maxN + 1][maxM + 1], sir[((maxN < maxM) ? maxM : maxN) + 1];

	in >> N >> M;
	for (unsigned i = 1; i <= N; ++i)
		LCS[i][0] = 0, in >> A[i];
	for (unsigned i = 1; i <= M; ++i)
		LCS[0][i] = 0, in >> B[i];
	LCS[0][0] = 0;

	for (unsigned i = 1; i <= N; ++i)
	{
		for (unsigned j = 1; j <= M; ++j)
		{
			if (A[i] == B[j])
				LCS[i][j] = 1 + LCS[i - 1][j - 1];
			else LCS[i][j] = std::max(LCS[i][j - 1], LCS[i - 1][j]);
		}
	}
	out << LCS[N][M] << '\n';
	unsigned len = LCS[N][M];
	for (unsigned i = N, j = M; i != 0 && j != 0;)
	{
		if (A[i] == B[j])
			sir[--len] = A[i], --i, --j;
		else if (LCS[i][j - 1] > LCS[i - 1][j])
			j = j - 1;
		else i = i - 1;
	}

	for (unsigned i = 0; i < LCS[N][M]; ++i)
		out << sir[i] << ' ';
	return 0;
}

#ifdef INFOARENA
}
#endif