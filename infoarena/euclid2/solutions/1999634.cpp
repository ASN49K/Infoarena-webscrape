#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n;
    fin >> n;
    long a, b;
    while(n)
    {
        fin >> a >> b;
        long x;
        if(b > a)
        {
            x = a;
            a = b;
            b = x;
        }
        while(a % b != 0)
        {
            x = a;
            a = b;
            b = x % b;
        }
        fout << b << "\n";
        n--;
    }
    return 0;
}
