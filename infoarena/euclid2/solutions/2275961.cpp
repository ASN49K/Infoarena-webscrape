#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("eculid2.out");

int main()
{
    unsigned long long a,b;
    int T;
    fin >> T;
    for (int i = 1;i <= T;i ++)
    {
        fin >> a >> b;
        int rest;
        while ( b )
        {
            rest = a % b;
            a = b;
            b = rest;
        }
        fout << a << endl;
    }
    return 0;
}
