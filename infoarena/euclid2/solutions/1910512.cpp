#include <iostream>
#include <fstream>

using namespace std;

int i, t;
int a, b, r;

int euc(int a, int b)
{
    cout << a << " " << b << "\n";
    if (!b) return a;
    return euc(b , a%b);
}

int main() {
    
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> t;
    for (i = 1; i <= t; i++)
    {
        fin >> a >> b;
        fout << euc(a, b) << "\n";
    }
    
    // !b inseamna b == 0;
}
