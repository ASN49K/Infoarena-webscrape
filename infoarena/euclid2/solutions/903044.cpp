#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Cmmdc(int t1, int t2)
{
    if ( !t2 ) return t1;
    return Cmmdc(t2, t1 % t2);
}

int main()
{
    int n;
    fin >> n;

    int t1, t2;
    while ( n-- )
    {
        fin >> t1 >> t2;
        fout << Cmmdc(t1, t2) << '\n';
    }


    fin.close();
    fout.close();
    return 0;
}
