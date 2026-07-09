using namespace std;
#include<fstream>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
	int x[100000][2], n, t, i, j;
	fin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=2;j++)
			fin>>x[i][j];
	for(i=1;i<=n;i++)
		{while(x[i][2])
		{	t=x[i][2];
			x[i][2]=x[i][1]%x[i][2];
			x[i][1]=t;
		}
		fout<<x[i][1]<<"\n";
		}
}