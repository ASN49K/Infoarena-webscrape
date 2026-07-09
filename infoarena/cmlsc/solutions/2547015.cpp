#include <iostream>
#include <fstream>

std :: ifstream f("../euclid2.in");
std :: ofstream g("../euclid2.out");

int main()
{
	int a[1025], b[1025], m[1025][1025] = {}, len_a, len_b;
	f >> len_a >> len_b;
	for(int i = 1; i <= len_a; i++)
		f >> a[i];
	for(int i = 1; i <= len_b; i++)
		f >> b[i];
	
	for(int i = 1; i <= len_a; i++)
		for(int j = 1; j <= len_b; j ++)
			if(a[i] == b[j])
				m[i][j] = m[i-1][j-1] + 1;
			else
				m[i][j] = (m[i-1][j] >= m[i][j-1] ? m[i-1][j] : m[i][j-1]);
	g << m[len_a][len_b] << '\n';
	int l = m[len_a][len_b];
	int t[l];
	int i = len_a, j = len_b;
	while(i && j)
	{
			if(a[i] == b[j])
			{
				t[l-1] = a[i];
				l--,i--,j--;
			}
			else
			{
					if(m[i-1][j] >m[i][j-1])
						i--;
					else
						j--;
			}
	}
	for( i= 0; i < m[len_a][len_b]; i++)
		g << t[i] << " ";
	
	
	
	f.close();
	g.close();
	return 0;
}
