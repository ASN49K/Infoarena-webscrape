#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a%b);
}

int main()
{
    int x;
    int nr1, nr2;
    fin >> x;
    for(int i = 1; i <=x; i++)
    {
        fin >> nr1 >> nr2;
        fout << gcd(nr1, nr2) << "\n";
    }
    return 0;
}
