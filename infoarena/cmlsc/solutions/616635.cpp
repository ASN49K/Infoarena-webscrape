#include <fstream>
#include <iostream>
#define max(a,b) ((a>b)?a:b)
using namespace std;



void cmlsc(int m, int n, int*A,int*B,int *&rez,int &k)
{
	

	
	int **Rez;
	Rez=new int*[m+1];
	for(int i=0;i<m+1;i++)
	{
		Rez[i]=new int[n+1];
		memset(Rez[i],0,4*(n+1));
	}
		
	k=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(A[i]==B[j])
			{
				Rez[i][j]=1+Rez[i-1][j-1];
				k++;
			}
			else
				Rez[i][j]=max(Rez[i-1][j],Rez[i][j-1]);
		}

	rez=new int[k];
	
	int i=m;
	int j=n;
	int contor=1;
	
	
	while (i)
	{
		if(A[i]==B[j])
		{
			rez[contor++]=A[i];
			i--;
			j--;
		}
		else
		{
			if(Rez[i-1][j]<Rez[i][j-1])
				j--;
			else
				i--;
		}

	}


}


int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int m,n,k,*A,*B,*rez;
	fin>>m>>n;
	A=new int[m];
	B=new int[n];
	for(int i=1;i<=m;i++)
		fin>>A[i];
	for(int j=1;j<=n;j++)
		fin>>B[j];
	fin.close();
	cmlsc(m,n,A,B,rez,k);
	fout<<k<<"\n";
	for(int i=k;i>=1;i--)
		fout<<rez[i]<<" ";
	
	fout.close();

	return 0;
}