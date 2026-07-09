#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n;
    fin >> n;
    
    for (int i = 1; i <= n; i++) {
        
        int a, b;
        fin >> a >> b;
        fout << __gcd(a, b) << "\n";
        
    }

    return 0;
}
