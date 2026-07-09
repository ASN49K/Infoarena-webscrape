#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,M,r;
    fin>>M;
    while(M);
    {
        M--;
        fin>>a>>b;
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a;
    }
    return 0;
}
