#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
    if(!b) return a;
    else gcd(b, a%b);
}

int main()
{
    int n;
    fin >> n;

    for(int i=0;i<n;i++){
        int a,b;
        fin >> a;
        fin >> b;
        fout << gcd(a,b) << '\n';
    }
    return 0;
}

