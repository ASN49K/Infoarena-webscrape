#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

    fstream fin("euclid2.in");
    fstream fout("euclid2.out");

    const long int T = 100000;
    const short int P = 2;
    int U[T][P];

    int cmmdc(int u, int v){
        int r = (u > v) ? (u%v) : (v%u);

        while(r!=0){
            u = v;
            v = r;
            r = (u > v) ? (u%v) : (v%u);
        };
        return v;
    };

    int main(){
        int N;
        fin >> N;


        for(int i = 0; i<=2*N; i++){
            for(int j = 0; j<=1; j++){
                fin >> U[i][j];
            };
        };

        for(int i = 0; i<=5; i++){
            fout << cmmdc(U[i][0], U[i][1]) << endl;
        };

        fin.close();
        fout.close();

    return 0;
    };
