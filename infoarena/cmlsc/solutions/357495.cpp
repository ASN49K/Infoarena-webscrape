// Cel mai lung subsir comun a doua siruri

#include <fstream>
#include <algorithm> 
using namespace std;

void Afisare(int,int);
int c[100][100]; //  -lungimea celui mai lung 
                //   subsir format care se poate gasi 
                //   in intervalul [0,i] in sirul a si [0,j] in sirul b
//int a[100] = {0 ,2 ,5, 2, 7, 4, 8};  
//int b[100] = {0 ,5 ,2, 5, 7, 1, 8};
int m, n, i, j;
int a[100], b[100];

ofstream fout("subsir.out");
ifstream fin("subsir.in");

int main()
{
   
    fin >> m >> n;
    for ( i = 1; i <= m; i++)
        fin >> a[i];
    for ( i = 1; i <= n; i++)
        fin >> b[i];
    fin.close();
    
    for ( i = 1; i <= m; i++)
        for ( j = 1; j <= n; j++)
        {
                if (a[i] == b[j])
                                c[i][j] = 1 + c[i-1][j-1];
                else
                                if ( c[i][j-1] > c[i-1][j])
                                                                c[i][j] = c[i][j-1];
                                else
                                                                c[i][j] = c[i-1][j];
        }

    fout << c[m][n] << '\n';
    Afisare(m, n);
    fout.close();
    fout << '\n';
    return 0;
}

void Afisare(int i, int j)
{
    if ( i == 0 || j == 0 )
        return;
    if ( a[i] == b[j])
    {
        Afisare(i - 1, j - 1);
        fout << a[i] << ' ';
    }
    else
        if ( c[i-1][j] > c[i][j-1])
                Afisare(i - 1, j);
       else
              Afisare(i, j - 1);
}            
                
