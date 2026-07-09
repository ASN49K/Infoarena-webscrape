#include<fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int N, M;
int A[1025], B[1025], sir[1025];
int C[1025][1025];

int main()
{	int i, j;
	
	f>>N>>M;
	
	for(i = 1; i <= N; i++)
		f>>A[i];
	for(j = 1; j <= M; j++)
		f>>B[j];
	
	for(i = 1; i <= N; i++)
		for(j = 1; j <= M; j++)
		{	if(A[i] == B[j])
				C[i][j] = C[i - 1][j - 1] + 1;
			else C[i][j] = max(C[i - 1][j], C[i][j - 1]);
		}
	
	i = N; j = M;
	while(i && j)
	{	if(A[i] == B[j])
		{	sir[++sir[0]] = A[i];
			i--;
			j--;
		}
		else 
		{	if(C[i - 1][j] > C[i][j - 1])
				i--;
			else j--;
		}
	}
	
	g<<C[N][M]<<'\n';
	for(i = sir[0]; i >= 1; i--)
		g<<sir[i]<<" ";
	
	f.close();
	g.close();
	return 0;
}