#include <fstream>
using namespace std;
int main ()
{
    int n, i, j, a, b;
    
    ifstream fin("euclid2.in");
    fin >> n;
    if ( n < 1 || n > 100000 )
    {
         ofstream fout("euclid2.out");
         fout << "Primul numar trebuie sa fie cuprins in intervalul [1,100.000]";
         fout.close();
    }
    else
    {
        ofstream fout("euclid2.out");
        for ( i = 1; i <= n; i++ )
        {
            fin >> a >> b;
            while ( b != 0 )
            {
                  j = a % b;
                  a = b;
                  b = j;
            }
            fout << a << endl;
        }
        fin.close();
        fout.close();
    }
    return 0;
}
