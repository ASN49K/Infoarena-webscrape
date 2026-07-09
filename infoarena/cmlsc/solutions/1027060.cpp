#include<fstream>
using namespace std;
int x[100][100];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{int a[100],b[100],n,m,c[100],pas=1,i,j;
fin>>n;
fin>>m;
for(i=1;i<=n;i++)
	fin>>a[i];
for(i=1;i<=m;i++)
	fin>>b[i];
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		if(a[i]==b[j])
			{x[i][j]=x[i-1][j-1]+1;
			c[pas]=a[i];
			pas++;
			}
		else
			if(x[i][j-1]>x[i-1][j])
				x[i][j]=x[i][j-1];
			else
				x[i][j]=x[i-1][j];
fout<<x[n][m]<<endl;
for(i=1;i<pas;i++)
	fout<<c[i]<<' ';
fin.close();
fout.close();
return 0;
}