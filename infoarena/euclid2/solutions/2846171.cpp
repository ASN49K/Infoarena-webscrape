#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    long long int n, a, b, r;

    fin >> n;

    for(long long int i = 1; i <= n; i++){
        fin >> a >> b;
        if (a < b)
            swap(a, b);
        r = a % b;
        while (r != 0){
            a = b;
            b = r;
            r = a % b;
        }
        fout << b << "\n";
    }

    return 0;
}
