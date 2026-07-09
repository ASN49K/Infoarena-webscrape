#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");


int main(){
    int T,N,x,S;
    fin >> T;
    while(T--){
        fin >> N;
        S = 0;
        while(N--){
            fin >> x;
            S ^= x;
        }
        fout <<(S!=0 ? "DA\n" : "NU\n");
    }

    return 0;
}
