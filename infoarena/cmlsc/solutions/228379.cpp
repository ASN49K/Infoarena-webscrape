#include <fstream.h>

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024], b[1024], c[1024];



int main()
{

	int m, n, i, j, k=0, d=0;
	fin>>m>>n;

	for(i=0; i < m; i++)
	fin>>a[i];

	for(i=0; i < n; i++)
	fin>>b[i];

	for(i=0; i < m; i++)
	{
		for(j=0; j < n; j++)
		if(a[i]==b[j])
		{
			d++;
			c[k]=a[i];
			k++;

		}
	}

fout<<k<<"\n";

for(i=0; i < k; i++)
fout<<c[i]<<" ";

return 0;
}


