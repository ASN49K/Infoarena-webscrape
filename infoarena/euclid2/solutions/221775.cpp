#include <fstream>
using namespace std;

int Cmmdc(int, int);

int main()
{
    int x, y, n;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> n;
    for ( int i = 0; i < n; i++)
       {
              fin >> x >> y;
              fout << Cmmdc(x, y) << '\n';
       }    
    fout.close();
    fin.close();
    return 0;
}

int Cmmdc(int a, int b)
{
    if ( b == 0 )  return a;
    int rest;
    do
    {
        rest = a % b;
        a = b;
        b = rest;
    } while ( rest );
    
    return a;
}

    
