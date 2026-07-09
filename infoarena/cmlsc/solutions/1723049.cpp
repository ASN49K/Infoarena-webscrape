#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int nmax = 1030;
int n, m, d[nmax][nmax], v1[nmax], v2[nmax], vrasp[nmax], lin, col, rasp;

int maxim(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main(){
	int player_unu=0;

	in>>n>>m;
	for(int i = 1; i<=n; i++)
		in>>v1[i];
	for(int i = 1; i<=m; i++)
		in>>v2[i];

	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++)
			d[i][j] = maxim(maxim(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1] + v2[j]==v1[i]);

	lin = n;
	col = m;
	while(lin>0)
	{
		if (v1[lin]==v2[col])
		{
            vrasp[rasp] = v1[lin];
			lin--;
			col--;
			rasp++;
		}
        else 
		{
			if(d[lin - 1][col] < d[lin][col-1])
			   col--;
			else
				lin--;
		}
	}

	out<<rasp<<'\n';
	for(int i = rasp - 1; i>=0; i--)
		out<<vrasp[i]<<' ';

	return player_unu;
}