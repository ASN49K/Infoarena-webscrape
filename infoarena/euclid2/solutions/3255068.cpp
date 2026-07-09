#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

    long long int T, a, b;
    fin>>T;
    for (int i=0; i<T; i++){
        fin>>a>>b;
        while (b!=0) {
            r = a%b;
            a = b;
            b = r;
        }
        fout << a << endl;
    }
    return 0;
}