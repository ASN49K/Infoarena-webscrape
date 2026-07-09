#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T;

int euclid(int a, int b);

int main(){

    fin>>T;
    int i, a, b;
    for(i = 1; i<= T; ++i){
        fin>>a>>b;
        fout<<euclid(a, b)<<'\n';
    }

    return 0;
}

int euclid(int a, int b){
    int r;
    if(b < a)swap(a, b);

    while(b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
