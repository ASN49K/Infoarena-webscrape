#include <fstream>
#include <vector>
using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int N, M, A[1024], B[1024];

	ifstream in("cmlsc.in");
	in >> M >> N;
	vector<vector<int>> C(M + 5, vector<int>(N + 5, 0));
	for (int i = 0; i < M; ++i)
	{
		in >> A[i];
	}
	for (int j = 0; j < N; ++j)
	{
		in >> B[j];
	}
	in.close();

	int maxim = M > N ? M : N;
	int minim = M > N ? N : M;
	C[maxim + 1][maxim + 1] = C[maxim][maxim + 1] =
		C[maxim + 1][maxim] = 0;
	for (int i = M; i >= 0; --i)
	{
		for (int j = N; j >= 0; --j)
		{
			C[i][j] = 0;
		}
	}
	for (int i = M; i >= 0; --i)
	{
		for (int j = N; j >= 0; --j)
		{
			if (i < M && j < N)
			{
				C[i][j] = max(max(C[i + 1][j + 1],
					C[i + 1][j]), C[i][j + 1]) +
					(A[i] == B[j] ? 1 : 0);
			}
		}
	}

	ofstream out("cmlsc.out");
	out << C[0][0] << endl;
	out.close();

	return 0;
}