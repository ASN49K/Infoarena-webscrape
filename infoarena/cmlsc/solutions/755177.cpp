#include<fstream>
#include<vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,x,k;
int vector1[1025],vector2[1025],roadCheck[100][100],roadTaken[1025];

void read()
{
	fin>>m>>n;
	int i;
	for(i=1;i<=m;i++)
	{
		fin>>vector1[i];
	}
	for(i=1;i<=n;i++)
	{
		fin>>vector2[i];
	}
}
void dinamica()
{	
	int x,y;
		for(x=1;x<=m;x++)
			for(y=1;y<=n;y++)
			{
				if(vector1[x]==vector2[y])
					{
						roadCheck[x][y]=roadCheck[x-1][y-1]+1;
						roadTaken[++k] = vector1[x];
					}
				else
				{
					if(roadCheck[x-1][y]>roadCheck[x][y-1])
						roadCheck[x][y]=roadCheck[x-1][y];
					else
						roadCheck[x][y] = roadCheck[x][y-1];
				}
			}
}

int main()
{
	read();
	dinamica();
	int i;
	fout<<roadCheck[m][n]<<'\n';
	for(i=1;i<=k;i++)
		fout<<roadTaken[i]<<' ';
	return 0;
}