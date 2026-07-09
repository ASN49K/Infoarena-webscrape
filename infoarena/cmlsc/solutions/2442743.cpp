#include <fstream>
#define MAX 1025

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int N, M, a[MAX], b[MAX], ans[MAX][MAX], rez[MAX], counter;

int main()
{
	in >> N >> M;

	for(int i = 1; i<=N; i++)
		in >> a[i];
	for(int i = 1; i<=M; i++)
		in >> b[i];

	for(int i = 1; i<=N; i++)
		for(int j = 1; j<=M; j++)
		{
			if(a[i] == b[j])
				ans[i][j] = ans[i-1][j-1] + 1;
			else
				ans[i][j] = max(ans[i][j-1], ans[i-1][j]);
		}

	int val = ans[N][M];
	int i = N;
	int j = M;
	while(val)
	{
		if(a[i] == b[j])
		{
			val--;
			rez[++counter] = a[i];
			i--;
			j--;
		}
		else
		{
			if(ans[i-1][j] > ans[i][j-1])
				i--;
			else
				j--;
		}
	}

	out << counter <<"\n";
	for(int i = counter; i>=1; i--)
		out << rez[i] <<' ';
	return 0;
}
