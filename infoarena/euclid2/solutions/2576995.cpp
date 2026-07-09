#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b, r, T, i=0;
    fin >> T;
    while(i!=T){
        fin >> a; fin >> b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fout << a << endl;
    }
    return 0;
}
