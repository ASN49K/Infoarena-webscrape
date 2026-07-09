#include <fstream>

using namespace std;

const int TMAX = 100000;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    unsigned T, a, b;
    fin >> T;

    for(unsigned int i = 0; i < T; i++)
    {
        fin >> a >> b;
        int r = a % b;
        while(r)
        {
            a = b;
            b = r;
            r = a % b;
        }
        fout << b << endl;
    }
    return 0;
}
