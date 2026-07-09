#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int T,n,i,val,x;

int main()
{
    fin >> T;
    for (;T--;)
    {
        fin >> n;
        fin >> val;
        for (i=2; i<=n; i++)
        {
            fin >> x;
            val ^= x;
        }
        if (val != 0)
            fout << "DA" << "\n";
        else
            fout << "NU" << "\n";
    }
    return 0;
}
