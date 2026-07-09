#include <fstream>
using namespace std;

int gcd(int a, int b)
{
    int temp;
    while(b!=0)
    {
       temp = b;
       b = a % b;
       a = temp;
    }
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int a, b, t;
    fin >> t;
    for(int i = 0; i < t; i++)
    {
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }
    return 0;
}
