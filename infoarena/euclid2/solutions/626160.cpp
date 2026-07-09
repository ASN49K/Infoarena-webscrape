#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b, c;

int main()
{
    fin >> n;
    for(;n;n--)
    {
        fin >> a >> b;
        while(b)
        {
            c = b;
            b = a%b;
            a = c;
        }
        fout << a <<'\n';
    }
    return 0;
}
