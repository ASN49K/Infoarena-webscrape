#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n;
    fin >> n;
    for(int i = 0; i < n; ++i){
        int nr1, nr2;
        fin >> nr1 >> nr2;
        while(nr2 != nr1){
            if(nr1 > nr2) nr1 = nr1- nr2;
            else nr2 = nr2 - nr1;
        }
        fout << nr1 << '\n';
    }
    return 0;
}
