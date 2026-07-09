#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long t, a, b, r;

int main(){
    fin >> t;
    for(int i = 1; i <= t; i++){
        fin >> a >> b;
        while(b){
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << endl;
    }
    return 0;
}
