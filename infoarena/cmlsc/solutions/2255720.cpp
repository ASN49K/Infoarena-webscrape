#include <fstream>
#include <vector>
using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int M, N;

	ifstream in("cmlsc.in");

	in >> M >> N;
	vector<int> A(M + 1), B(N + 1);
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
	C[maxim + 1][maxim + 1] = C[maxim][maxim + 1] =
		C[maxim + 1][maxim] = 0;
	for (int i = M; i >= 0; --i)
	{
		for (int j = N; j >= 0; --j)
		{
			C[i][j] = 0;
		}
	}
	vector<bool> Fol(M + 1, false);
	for (int i = M; i >= 0; --i)
	{
		for (int j = N; j >= 0; --j)
		{
			if (i < M && j < N)
			{
				C[i][j] = max(
					max(C[i + 1][j + 1],
					C[i + 1][j]),
					C[i][j + 1]);
				if (!Fol[i] && A[i] == B[j])
				{
					Fol[i] = true;
					C[i][j] += 1;
				}
			}
		}
	}

	vector<pair<int, int>> sir(0);
	int i = 0, j = 0;
	sir.push_back(make_pair(0, 0));
	while (true)
	{
		int v = C[i][j] - (A[i] == B[j] ? 1 : 0);
		if (v == C[i + 1][j + 1])
		{
			sir.push_back(make_pair(i + 1, j + 1));
			i++; j++;
		}
		else if (v == C[i][j + 1])
		{
			sir.push_back(make_pair(i, j + 1));
			j++;
		}
		else if (v == C[i + 1][j])
		{
			sir.push_back(make_pair(i + 1, j));
			i++;
		}
		if (i >= M || j >= N)
		{
			break;
		}
	}

	ofstream out("cmlsc.out");
	out << C[0][0] << endl;
	for (int i = 1; i < sir.size(); ++i)
	{
		pair<int, int> p = sir[i - 1];
		pair<int, int> p2 = sir[i];
		if (C[p.first][p.second] != C[p2.first][p2.second])
		{
			out << A[p.first] << ' ';
		}
	}
	out << endl;
	out.close();

	return 0;
}