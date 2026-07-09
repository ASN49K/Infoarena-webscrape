#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int A, B, i;

int gcd(int a, int b)
{
    if(!b) return a;
    else if(a > b) return gcd(a-b, b);
    else return gcd(a, b-a);
}

int main()
{
    fin >> i;

    for(; i; i--) {
        fin >> A >> B;
        fout << gcd(A, B) << "\n";
    }

    return 0;
}
