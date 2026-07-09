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
    ofstream fout("euclid2.in");

    int a, b;
    fin >> a >> b;
    fout << gcd(a,b);
    return 0;
}
