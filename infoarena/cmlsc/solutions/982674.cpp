#include<fstream>
using namespace std;

int main(void) 
{
	ifstream in;
	ofstream out;
	in.open("cmlsc.in");
	out.open("cmlsc.out");

	int m,n;
	in >> m >> n;

	int *a = new int[m+1];
	int *b = new int[n+1];

	int **c = new int*[m+1];
	for(int loop=0;loop<=m;++loop)
		c[loop] = new int[n+1];

	c[0][0] = 0;
	for(int loop=1;loop<=m;++loop)
	{
		in >> a[loop];
		c[loop][0] = 0;
	}
	for(int loop=1;loop<=n;++loop)
	{
		in >> b[loop];
		c[0][loop] = 0;
	}


	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
		{
			if(a[i] == b[j])
				c[i][j] = c[i-1][j-1] + 1;
			else
			{
				if(c[i-1][j] > c[i][j-1])
					c[i][j] = c[i-1][j];
				else
					c[i][j] = c[i][j-1];
			}
		}

	out << c[m][n] << "\n";
	
	int *sol = new int[c[m][n]];

	int i = m;
	int j = n;
	int p = c[m][n]-1;
	while(i > 0 && j > 0) 
	{
		if(a[i] == b[j]) {
			sol[p--] = a[i];
			--i; --j;
		}
		else
		{
			if(c[i][j] == c[i-1][j])
				--i;
			else
				--j;
		}
	}

	for(int loop=0;loop<c[m][n];++loop)
	{
		out << sol[loop] << " ";
	}

	delete[] sol;

	for(int loop=0;loop<m;++loop)
		delete[] c[loop];
	delete[] c;

	delete[] a;
	delete[] b;
	in.close();
	out.close();
	return 0;
}
