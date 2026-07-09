#include <fstream>
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long T,x,a,b;
    fin >> T;
    for(int i = 0; i<T; ++i) {
       fin >> a; fin>>b;
       fout << gcd(a,b) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
