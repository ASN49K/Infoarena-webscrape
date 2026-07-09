#include<fstream>
using namespace std;
#define Dmax 1025
ifstream intrare("subsir.in");
ofstream iesire("subsir.out");
int a[Dmax],b[Dmax],LCS[Dmax][Dmax],OP[Dmax][Dmax];
int n,m;
void pd()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			if(a[i]==b[j])
			{
				LCS[i][j]=LCS[i+1][j+1]+1;
				OP[i][j]=1;
			}
			else
				if(LCS[i+1][j]>LCS[i][j+1])
				{
					LCS[i][j]=LCS[i+1][j];
					OP[i][j]=2;
				}
				else
					if(LCS[i+1][j]<LCS[i][j+1])
					{
						LCS[i][j]=LCS[i][j+1];
						OP[i][j]=3;
					} 
	}
}
int main()
{
	int i,j;
	intrare>>n>>m;
	for(i=0;i<n;i++)
		intrare>>a[i];
	for(j=0;j<m;j++)
		intrare>>b[j];
	pd();
	iesire<<LCS[0][0]<<'\n';
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(OP[i][j]==1)
				if(i>j)
					iesire<<i<<' ';
				else
					iesire<<j<<' ';
	iesire<<'\n';	
	iesire.close();
	return 0;
}
