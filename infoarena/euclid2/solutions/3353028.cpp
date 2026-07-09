#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n;
    fin >> n;

    while (n--){
        int a, b;

        fin >> a >> b;

        int r;
        while (b){
            r = a % b;
            a = b;
            b = r;
        }

        fout << a << '\n';
    }


    return 0;
}
