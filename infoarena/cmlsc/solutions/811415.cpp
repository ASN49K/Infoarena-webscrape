#include <fstream>

using namespace std;
int sol[200][200];
	int is;
int n,m,a[225],b[225],i,LCS[225][225],op[225][225];

int lg()
{
	int x,y;
	
	for (x=n-1;x>=0;x--)
		for (y=m-1;y>=0;y--)
		{
			if (a[x]==b[y])
			{
				op[x][y]=1;
				LCS[x][y]= 1+LCS[x+1][y+1];
			}
			else
			{
				if (LCS[x+1][y]>=LCS[x][y+1])
				{
					op[x][y]=2;
					LCS[x][y]=LCS[x+1][y];
				}
				else
				{
					op[x][y]=3;
					LCS[x][y]=LCS[x][y+1];
				}
			}
		}
}

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	//f>>n>>m;
	char c;
	f.get(c);
	for (n=0;c!='\n';n++)
	{
		a[n]=c-'0';
		f.get(c);
	}
	
	f.get(c);
	for (m=0;c!='\n';m++)
	{
		b[m]=c-'0';
		f.get(c);
	}
	
	//g<<lg(0,0)<<'\n';
	lg();
	
	int x=0, y=0;
while (x<n && y<m)
		{
			if (op[x][y]==1)
			{
				sol[is][ind++]=a[x];//<<' ';
				x+=1,y+=1;
			}
			else
				if (op[x][y]==2)
					x+=1;
				else
					y+=1;
		}
	f.close();
	g.close();
return 0;
}
