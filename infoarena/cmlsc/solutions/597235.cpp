// LCS - Longest Common Subsequence - O(n*m)

#include<fstream>
#include<cmath>
using namespace std;
short n,m,A[1050],B[1050];
short LCS[1050][1050];
// LCS[i][j] = lg maxima a unui subsir comun al lui A[i...n] si B[j...m]

void Citire()
{
	int i;
	ifstream fin("cmlsc.in");
	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>A[i];
	for(i=1;i<=m;i++)
		fin>>B[i];
	fin.close();
}

inline short max(short a,short b)
{
	if(a<b)
		return b;
	return a;
}

void Determinare_LCS()
{
	int i,j,gasit;
	//Initializari
	gasit=0;
	for(i=n;i>0;i--)
	{
		if(gasit==1)
			LCS[i][m]=1;
		else
		{
			if(A[i]==B[m])
			{
				gasit=1;
				LCS[i][m]=1;
			}
			else
				LCS[i][m]=0;
		}
	}
	gasit=0;
	for(j=m;j>0;j--)
	{
		if(gasit==1)
			LCS[n][j]=1;
		else
		{
			if(A[n]==B[j])
			{
				gasit=1;
				LCS[n][j]=1;
			}
			else
				LCS[n][j]=0;
		}
	}
	//Construirea matricii LCS in mod bottom-up
	for(i=n-1;i>0;i--)
	{
		for(j=m-1;j>0;j--)
		{
			if(A[i]!=B[j])
			{
				LCS[i][j]=max(LCS[i+1][j],LCS[i][j+1]);
			}
			else
			{
				LCS[i][j]=max(1+LCS[i+1][j+1],max(LCS[i+1][j],LCS[i][j+1]));
			}
		}
	}
}

void Afisare()
{
	int i,j;
	ofstream fout("cmlsc.out");
	fout<<LCS[1][1]<<"\n";  // LCS[1][1] este lungimea maxima a subsirului comun
	i=1;
	j=1;
	while(LCS[i][j]!=0)
	{
		if(A[i]!=B[j])
		{
			if(LCS[i+1][j]>LCS[i][j+1])
				i++;
			else
				j++;
		}
		else
		{
			fout<<A[i]<<' ';
			i++;
			j++;
		}
	}
	fout<<"\n";
	fout.close();
}

int main()
{
	Citire();
	Determinare_LCS();
	Afisare();
	return 0;
}
