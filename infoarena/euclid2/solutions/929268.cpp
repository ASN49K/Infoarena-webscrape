#include <fstream>
using namespace std;
int main ()
{
    int n, i, j, a, b;
    
    ifstream fin("euclid2.in");
    fin >> n;
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
    
    return 0;
}
