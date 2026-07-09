#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long a, b, n;

int main()
{
    fin >> n;
    while (n--){
        fin >> a >> b;
        while (b){
            a %= b;
            swap(a, b);
        }
        fout << a << endl;
    }

    return 0;
}