#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M,N,A[1025],B[1025],c[1025][1025];
int k=0,p[1025];

void Prelucreaza(int m, int n)
{
    if(m==0 or n==0);
	else if(A[m]==B[n])
	{
		p[k++]=A[m];
		Prelucreaza(m-1,n-1);
    }
    else if(c[m-1][n]>=c[m][n-1])
        Prelucreaza(m-1,n);
    else
        Prelucreaza(m,n-1);
}
void CMLSC()
{
	for(int i=1;i<=M;i++)
	    for(int j=1;j<=N;j++)
	        if(A[i]==B[j])
	        	c[i][j]=c[i-1][j-1]+1;
			else
			    c[i][j]=max(c[i][j-1],c[i-1][j]);
}
void Citeste()
{
	fin >> M >> N;
	for(int i=1;i<=M;i++)
	    fin >> A[i];
	for(int j=1;j<=N;j++)
	    fin >> B[j];;
}
void Afiseaza()
{
	fout << k << endl;
	for(int i=k-1;i>=0;i--)
	    fout << p[i] << " ";
}

int main()
{
    
    Citeste();
    CMLSC();
    Prelucreaza(M,N);
    Afiseaza();
    
    return 0;
    
}
