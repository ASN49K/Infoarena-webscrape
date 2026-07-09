#include<fstream>
using namespace std;

int a[201], b[201], v[201][201], i, j, na, nb;
int sol[201];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
	fin>>na>>nb;
	for(i=1;i<=na;++i)
		fin>>a[i];
	for(i=1;i<=nb;++i)
		fin>>b[i];
	for(i=1;i<=na;i++)
		for(j=1;j<=nb;j++)
		{
			if(a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				if(v[i-1][j]>v[i][j-1])
					v[i][j]=v[i-1][j];
				else
					v[i][j]=v[i][j-1];
		}
	i=na,j=nb;
	int k=0;
	
	while(i)
        if (a[i] == b[j])
            sol[++k] = a[i], --i, --j;
        else if (v[i-1][j] < v[i][j-1])
            --j;
        else
            --i;

	for(i=k;i>=1;i--)
		fout<<sol[i];
	fout<<'\n';
	fin.close();
	fout.close();
	return 0;
}
