#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int N, M, A[1024], B[1024], D[1024][1024], S[1024], MAX;

void read()
{
	in >> N >> M;
	for(int i = 1; i <= N; ++i)
		in >> A[i];
	for(int j = 1; j <= M; ++j)
		in >> B[j];
}

void solve()
{
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= M; ++j)
			if(A[i] == B[j])
				D[i][j] = D[i-1][j-1] + 1;
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);

	for(int i = N, j = M; i > 0;)
		if(A[i] == B[j])
			S[++MAX] = A[i], --i, --j;
		else if(D[i-1][j] < D[i][j-1])
			j--;
		else
			i--;
}

void afis()
{
	out << MAX << '\n';
	for(int i = MAX; i > 0; --i)
		out << S[i] << ' ';
}

int main()
{
	read();
	solve();
	afis();
	return 0;
}