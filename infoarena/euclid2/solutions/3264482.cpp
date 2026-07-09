/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }

    return a;
}

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int t, x, y;
    fin >> t;

    for (int i = 1; i <= t; i++) {
        fin >> x >> y;

        int cmmdc = euclid(x, y);

        fout << cmmdc << endl;
    }
    return 0;
}