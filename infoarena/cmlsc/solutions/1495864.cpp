#include<fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define MAX(a,b) a>b ? a:b

int N, M;
short x[1026], y[1026],z[1026];
short D[1026][1026];
void cmlsc()
{
	int i, j;
	for (i = 1;i <= N;++i)
		for (j = 1;j <= M;++j)
			if (x[i] == y[j])
				D[i][j] = D[i - 1][j - 1] + 1;
			else
				D[i][j] = MAX(D[i - 1][j], D[i][j - 1]);
	--i, --j;

	int l = D[i][j];
	out << l << '\n';
	int r = l;
	while (D[i][j])
	{
		if (D[i - 1][j - 1] == D[i][j] - 1)
			z[l--] = x[i], --i, --j;
		else if (D[i - 1][j] == D[i][j])
			--i;
		else if(D[i][j-1]==D[i][j])
			--j;

	}

	for (i = 1;i <= r;++i)
		out << z[i] << " ";
}


int main()
{
	in >> N >> M;
	
	int i;
	for (i = 1;i <= N;++i)
		in >> x[i];
	for (i = 1;i <= M;++i)
		in >> y[i];
	cmlsc();
	in.close();
	out.close();

	return 0;
}