#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;


ifstream intrare;
ofstream iesire;

int main()
{
	
	int n,m, v1[1025], v2[1025], M[1025][1025]; 

	intrare.open("cmlsc.in");
	intrare>>n>>m;
	for(int i=1;i<=n;i++)
		intrare>>v1[i];
	for(int i=1;i<=m;i++)
		intrare>>v2[i];
	intrare.close();

	for(int i=0;i<=n;i++)
		M[i][0] = 0;
	for(int j=0;j<=m;j++)
		M[0][j] = 0;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(v1[i] == v2[j])
				M[i][j] = M[i-1][j-1]+1;
			else
				M[i][j] = max(M[i-1][j], M[i][j-1]);

	iesire.open("cmlsc.out");
	iesire<<M[n][m]<<"\n";
	for(int i=1;i<=n;i++)
		if(M[i][m]>M[i-1][m])
			iesire<<v1[i]<<" ";
	iesire.close();
	return 0;
}