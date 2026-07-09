//algoritm folosit pentru antrenarea la clasa
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void Scrie(int , int );
int c[100][100], a[100], b[100];
int Max(int , int );
int lmax;

int main()
{
    int i, j, m, n;
    fin >> m >> n;
    
	
    for ( i = 1; i <= m; ++i )
        fin >> a[i];
    for ( j = 1; j <= m; ++j )
        fin >> b[j];
    
    for ( i = 1; i <= n; ++i )
        for ( j = 1; j <= m; ++j )
            if ( a[i] == b[j] )
			{
				c[i][j] = 1 + c[i-1][j-1];
					lmax++;
			}
            else
                {
					c[i][j] = Max(c[i-1][j],c[i][j-1]);
				}
    
    Scrie ( m, n );
    fin.close();
    fout.close();
}    

void Scrie(int i, int j)
{
    if ( i == 0 || j == 0 )
        return;
    if ( a[i] == b[j] )
    {
        Scrie ( i-1, j-1 );
        fout << lmax << a[i] << ' ';
    }    
    else
        if ( c[i-1][j] > c[i][j-1] )
                Scrie ( i-1, j );
        else
                Scrie ( i, j-1 );
}    


int Max ( int i, int j )
{
    if  ( i > j )
        return i;
    return j;
}    

