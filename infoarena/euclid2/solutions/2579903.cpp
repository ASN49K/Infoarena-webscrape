#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

    fstream fin("euclid2.in");
    fstream fout("euclid2.out");

    int euclid(int x, int y){
        if(!y){
            return x;
        }else{
        return euclid(y, x%y)
        };
    };

    int main(){
        int N, a, b;
        fin >> N;

        for(int i = 1; i<=N; i++){
            fin >> a >> b;
            fout << euclid(a, b) << "\n";
        };

        fin.close();
        fout.close();

    return 0;
    };


