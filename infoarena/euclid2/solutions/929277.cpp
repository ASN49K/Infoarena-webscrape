#include <fstream>
using namespace std;
int main ()
{
    int n, i, j, a, b;
    
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> n;
    for ( ; n >= 1; n-- )
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
    fout.close();
    fin.close();
    return 0;
}
