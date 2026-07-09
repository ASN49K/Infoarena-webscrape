#include <iostream>
#include <fstream>

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
using namespace std;
int main() {
    int nr1 = 12 , nr2 = 42,n,  rest;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> nr1 >> nr2;
        while (nr2)
        {
            rest = nr1 % nr2;
            nr1 = nr2;
            nr2 = rest;
        }
        fout << nr1 << "\n";
    }
           
       

    return 0;
}