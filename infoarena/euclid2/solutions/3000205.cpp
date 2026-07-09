#include <fstream>

using namespace std;

#define INFILE "euclid2.in"
#define OUTFILE "euclid2.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int n, nr_1, nr_2;

int euclid(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve(){

    fin >> n;

    for(int i = 0; i < n; ++i){
        
        fin >> nr_1 >> nr_2;

        fout << euclid(nr_1, nr_2) << '\n';

    }

}

int main(){
    solve();
    return 0;
}