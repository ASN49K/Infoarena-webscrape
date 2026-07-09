#include <fstream>
#define DIM 1025
using namespace std;

int n, m;
int a[DIM], b[DIM];
int c[DIM][DIM];


void Read();
void Dinamic();
int Max(int, int);
void Write(int, int);
ofstream fout("cmlsc.out");


int main()
{
    Read();
    Dinamic();
    fout << c[n][m] << "\n";
    Write(n, m);
    
    
    fout.close();
    return 0;
}

void Read()
{
     ifstream fin("cmlsc.in");
     fin >> n >> m;
     
     for (int i = 1; i <= n; i++)
         fin >> a[i];
     for (int j = 1; j <= m; j++)
         fin >> b[j];
 
     fin.close();
}

int Max(int i, int j)
{
    if (i >= j) return i;
    return j;
}

void Dinamic()
{
     for (int i = 1; i <= n; i++)
         for (int j = 1; j <= m; j++)
             if (a[i] == b[j]) c[i][j] = c[i-1][j-1] + 1;
             else c[i][j] = Max(c[i-1][j], c[j][i-1]);
}

void Write(int i, int j)
{
	if ( i == 0  ||  j == 0 ) return;
	if ( a[i] == b[j] )
	{
		Write( i - 1, j - 1 );
		fout << a[i] << " ";
	}
	else
		if ( c[i-1][j] >= c[i][j-1] ) Write( i - 1, j );
		else                         Write( i, j - 1 );
}
