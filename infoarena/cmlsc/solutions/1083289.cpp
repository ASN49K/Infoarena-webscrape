#include <fstream>
#define IN "cmlsc.in"
#define OUT "cmlsc.out"
#define NMAX 1030

using namespace std;

ifstream in(IN);
ofstream out(OUT);

int t[NMAX][NMAX], a[NMAX], b[NMAX], sol[NMAX];

inline int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

int main()
{
	int na, nb, i, j, ind=0;
	in>>na>>nb;
	for(i=1; i<=na; ++i)
		in>>a[i];
	for(i=1; i<=nb; ++i)
		in>>b[i];
	for(i=1; i<=na; ++i)
		for(j=1; j<=nb; ++j)
			if(a[i]==b[j])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i-1][j], t[i][j-1]);
	out<<t[na][nb]<<'\n';
	i=na, j=nb;
	while(ind<t[na][nb])
	{
		if(a[i]==b[j])
		{
			sol[++ind]=a[i];
			--i, --j;
		}
		else if(t[i-1][j] < t[i][j-1])
			--i;
		else --j;
	}
	for(i=ind; i>=1; --i)
		out<<sol[i]<<' ';
	out<<'\n';
	in.close();
	out.close();
	return 0;
}
