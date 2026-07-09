#include <fstream>
using namespace std;

int a[1025],b[1025],v[1025][1025];

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void print(int x,int y)
{
	if (!v[x][y])
		return;
	if (a[x]==b[y])
	{
		print(x-1,y-1);
		out<<a[x]<<" ";
		return;
	}
	if (v[x][y]==v[x-1][y])
	{
		print(x-1,y);
		return;
	}
	print(x,y-1);
}

int main()
{
	int i,j;
	in>>a[0]>>b[0];
	for (i=1;i<=a[0];i++)
		in>>a[i];
	for (i=1;i<=b[0];i++)
		in>>b[i];
	for (i=1;i<=a[0];i++)
		for (j=1;j<=b[0];j++)
			if (a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=max(v[i][j-1],v[i-1][j]);
	out<<v[a[0]][b[0]]<<"\n";
	print(a[0],b[0]);
	return 0;
}
