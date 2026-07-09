#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b, r, T;
    fin >> T;
    while(T>0){
        fin >> a; fin >> b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        T--;
        fout << a << " ";
    }
    return 0;
}
