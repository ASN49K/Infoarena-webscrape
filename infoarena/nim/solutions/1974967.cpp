#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int totalTests, totalNumbers;

int main(){
    fin >> totalTests;

    int number, xorSum;
    for ( ; totalTests; totalTests-- ){

        fin >> totalNumbers;

        xorSum = 0;
        for ( ; totalNumbers; totalNumbers-- ){

            fin >> number;
            xorSum ^= number;
        }

        fout << ( xorSum ? "DA\n" : "NU\n" );
    }
    return 0;
}
