#include<fstream> 
#define DIM 1025
using namespace std; 

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int Best[DIM][DIM], S1[DIM], S2[DIM], contor, sol[DIM];
int N, M;

int main()
{
	int i, j;
	
	in >> N >> M;
	for(i = 1; i <= N; i++)
		in >> S1[i];
	
	for(i = 1; i <= M; i++)
		in >> S2[i];
	
	for(i = 0; i <= N; i++)
		Best[i][0] = 0;
	for(i = 0; i <= M; i++)
		Best[0][i] = 0;
	
	for(i = 1; i <= N; i++)
		for(j = 1; j <= M; j++)
		{
			if( S1[i] == S2[j] )
				Best[i][j] = 1 + Best[i-1][j-1];
			else
				Best[i][j] = max(Best[i-1][j], Best[i][j-1]);
		}
		
		out << Best[N][M] << '\n';
		
		i = N; j = M;
		while( i && j )
		{
			if( S1[i] == S2[j] )
				sol[++contor] = S1[i], --i, --j; 
			else
		    if( Best[i][j-1] < Best[i-1][j] )
				i--;
			else 
				j--;
		}
		
		for(i = contor; i >= 1; i--)
			out << sol[i] << " ";
}
