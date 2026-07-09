#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned int T, a, b;
unsigned int cmmdc(unsigned int x, unsigned int y)
{
    if(!y)
        return x;
    return cmmdc(y, x % y);
}
int main()
{
    fin >> T;
    for(unsigned int i = 0; i < T; ++i)
    {
        fin >> a >> b;
        fout << cmmdc(a,b) << '\n';
    }
    return 0;
}
