#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

vector<int> max_seq;
unsigned int lcs = 0;
int LCS(vector<int> a, vector<int> b, int na, int nb, vector<int>& seq)
{
	if (na < 0 || nb < 0)
	{
		if (seq.size() > lcs)
		{
			lcs = seq.size();
			max_seq = seq;
		}
		return 0;
	}
	int val1 = 0;
	if (a[na] == b[nb])
	{
		seq.push_back(a[na]);
		val1 = 1 + LCS(a, b, na - 1, nb - 1, seq);
		seq.pop_back();
	}
	return max(val1,
		max(LCS(a, b, na - 1, nb, seq),LCS(a, b, na, nb - 1, seq)));
}
void ReadVector(vector<int>& v, int n)
{
	for (int i = 0; i < n; i++)
	{
		in >> v[i];
	}
}
int main()
{
	int M, N;
	in >> M >> N;
	vector<int> a(M, 0);
	vector<int> b(N, 0);
	ReadVector(a, M);
	ReadVector(b, N);
	vector<int> seq;
	out << LCS(a, b, M - 1, N - 1, seq) << '\n';
	for (auto it = max_seq.rbegin(); it != max_seq.rend(); it++)
	{
		out << *it << ' ';
	}
}