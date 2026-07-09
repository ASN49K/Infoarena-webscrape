/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, x, y;
    
    fin >> n;
    
    for (int i = 0; i < n; i++) {
        fin >> x >> y;
        fout << cmmdc(x, y) << endl;
    }
    
    return 0;
}