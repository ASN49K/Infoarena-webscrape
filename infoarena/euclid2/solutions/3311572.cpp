#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){

    int tests;
    fin >> tests;

    for(int test = 0; test < tests; test++){
        int a, b;
        fin >> a >> b;

        if(a < b){
            int aux = a;
            a = b;
            b = aux;
        }

        int r = a % b;
        while(r != 0){
            a = b;
            b = r;
            r = a % b;
        }

        fout << b << endl;
    }
    return 0;
}


