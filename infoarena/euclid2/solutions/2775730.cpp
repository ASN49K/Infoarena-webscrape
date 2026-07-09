#include <iostream>
#include <fstream>

using namespace std;

long long int gcd(long long int a, long long int b)
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}

int main(void)
{
    int n;
    long long int a, b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> n;

    while(n) {
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
        n--;
    }

    return 0;
}
