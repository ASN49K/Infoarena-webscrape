#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
    if (b > a) {
        int aux = a;
        a = b;
        b = aux;
    }
    int r;
    while(b) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {

    fstream filein;
    fstream fileout;


    int x;
    filein.open("euclid2.in",ios::in);
    fileout.open("euclid2.out", ios::out);
    
    filein >> x;

    while(x) {
        int m,n;
        filein >> m >> n;
        
        fileout << cmmdc(m,n) << endl;
        x--;
    }
}