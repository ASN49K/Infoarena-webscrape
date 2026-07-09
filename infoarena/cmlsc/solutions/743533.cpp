#include<iostream>
#include<fstream>

using namespace std;

const int maxn = 1 << 10;

int m, n, a[maxn], b[maxn], d[maxn][maxn], sir[maxn], rez;

inline int maxim(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

void read()
{
	ifstream in("cmlsc.in");
	
	int i;
	
	in >> m >> n;
	
	for(i = 1; i <= m; ++i)
		in >> a[i];
	
	for(i = 1; i <= n ; ++i)
		in >> b[i];
}

void dinamica()
{
	int i, j;
	
	for(i = 1; i <= m; ++i)
		for(j = 1; j <= n; ++j)
			if(a[i] == b[j])
				d[i][j] = 1 + d[i-1][j-1];
			else
				d[i][j] = maxim(d[i-1][j], d[i][j-1]);
			
	rez = 0;
	
	for(i = m, j = n; i; )
		if(a[i] == b[j])
			sir[ ++rez ] = a[i], --i, --j;
		else
			if(d[i-1][j] < d[i][j-1])
				--j;
			else
				--i;
}

void write()
{
	ofstream out("cmlsc.out");
	
	int i;
	
	out << rez;
	
	for(i = rez; i; --i)
		out << sir[i] << " ";
}

int main()
{
	read();
	dinamica();
	write();
	
	return 0;
}