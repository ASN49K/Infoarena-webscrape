#include <fstream.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int rs[1025],r,A[1025],B[1025],m,n,X[1025][1025];
int main()
{
    int j,i;
    fin >> n >> m;
    for(i = 1;i<=n;i++)
	{
        fin >> A[i];
    }
    for(i = 1;i<=m;i++)
	{
        fin >> B[i];
    }
      
    for(i = 1;i<=n;i++)
        for(j = 1;j<=m;j++)
		{
            if(A[i] == B[j]) X[i][j] = X[i-1][j-1] + 1;else
            X[i][j] = max(X[i-1][j],X[i][j-1]);
        }
    fout << X[n][m]<<'\n';
      
    for(i = n,j = m;i; )
	{
        if(A[i] == B[j])
		{
            rs[++r] = A[i];
            i--;
            j--;
        }
		else if(X[i-1][j] < X[i][j-1]) j--; else i--;
    }
      
    for(i = r;i>0;i--) fout << rs[i] <<' ';
    
    return 0;
}
