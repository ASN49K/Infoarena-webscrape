//Cel mai lung subsir comun a 2 multimi
//https://infoarena.ro/problema/cmlsc
#include <fstream>
#define MAXN 1025
using namespace std;
int x[MAXN],y[MAXN],v[MAXN],lgx,lgy;			//lungimea lui X si lungimea lui Y
int lcs[100][100];
void read();
void solve();
void write();
int main()
{
	read();
	solve();
	write();
	return 0;
}
void read()
{
	ifstream fin("cmlsc.in");
	fin>>lgx>>lgy;
	for (int i=1;i<=lgx;i++)
		fin>>x[i];
	for (int i=1;i<=lgy;i++)
		fin>>y[i];
	fin.close();
}
void solve()
{
	for (int k=1;k<=lgx;k++)				//prefixul lui a de lg K
		for (int h=1;h<=lgy;h++)				//prefixul lui b de lg H
			if (x[k]==y[h])					//daca elementele sunt egale, lungimea subsirului= lungimea subsirului anterior+1
				lcs[k][h]=lcs[k-1][h-1]+1;
			else
				lcs[k][h]=max(lcs[k-1][h],lcs[k][h-1]);

	//reconstituirea intr-un vector
	for (int i=0,k=lgx,h=lgy; lcs[k][h]!=0;)
	{
		if (x[k]==y[h])
		{
			v[i]=x[k]; i++; k--; h--;
		}
		else
		{
			if (lcs[k][h]==lcs[k-1][h])
				k--;
			else
				h--;
		}
	}
}
void write()
{
	ofstream fout("cmlsc.out");
	fout<<lcs[lgx][lgy]<<'\n';
	for (int i=lcs[lgx][lgy]-1;i>=0;i--)
		fout<<v[i]<<' ';
	fout.close();
}