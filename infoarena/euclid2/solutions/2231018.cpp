#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t;

int euclid(int a, int b) {

    int d = 0;

    while(a % 2 == 0 && b % 2 == 0) {

        a /= 2;
        b /= 2;
        d++;
    }

    while(a != b) {

        if(a % 2 == 0)
            a /= 2;
        else if(b % 2 == 0)
            b /= 2;
        else if(a > b)
            a = (a - b) / 2;
        else
            b = (b - a) / 2;
    }

    return a * int(pow(2.0 , d));
}

int main()
{
    fin >> t;

    int a, b;

    for(int i = 1; i <= t; i++) {

        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }
    return 0;
}
