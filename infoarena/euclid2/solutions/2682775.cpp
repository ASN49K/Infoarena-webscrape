#include <fstream>
#include <iostream>

using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
long long int n,a,b,r;
int main()
{
    fin >> n;
    while (n)
    {
        fin >> a >> b;
        if (a < b)
            swap(a, b);
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a <<'\n';
        n--;
    }
    return 0;
}
