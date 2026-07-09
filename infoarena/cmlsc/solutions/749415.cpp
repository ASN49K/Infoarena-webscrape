#include <vector>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;
const int N_MAX=1031;

int C[N_MAX][N_MAX];
int main()
{
	int i, j, k;
	int v[3][N_MAX];
	
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	
	in>>v[0][0]>>v[1][0];
	for(i=1; i <= v[0][0]; ++i)
		in>>v[0][i];
	for(j=1; j <= v[1][0]; ++j)
		in>>v[1][j];
	for(i=1; i <= v[0][0]; ++i)
		for(j=1; j <= v[1][0]; ++j)
			if(v[0][i] == v[1][j])
			{
				C[i][j]=1+C[i-1][j-1];
			}
			else C[i][j]= C[i-1][j] >= C[i][j-1] ? C[i-1][j] : C[i][j-1];

	v[2][0]=C[v[0][0]][v[1][0]];
	for(k=v[2][0], i=v[0][0], j=v[1][0]; i && j; )
		if(v[0][i] == v[1][j])
			v[2][k]=v[0][i], --k, --i, --j;
		else if(C[i-1][j] >= C[i][j-1])
				--i;
			 else --j;
	out<<v[2][0]<<'\n';
	copy(v[2]+1, v[2]+v[2][0]+1, ostream_iterator<int>(out, " ") );
	out<<'\n';

	return EXIT_SUCCESS;
}