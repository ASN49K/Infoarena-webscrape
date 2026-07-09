#include <fstream>
#include <vector>

using namespace std;

#define INFILE "euclid2.in"
#define OUTFILE "euclid2.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

// algoritmul lui euclid
int GCD(int a, int b){
    if(!a){
        return b;
    }
    return GCD(b, a%b);
}

int t, nr_1, nr_2, aux;
vector<int> v;

int main(){

    // citirea si prelucrarea
    fin >> t;
    for(int i = 0; i < t; i++){
        fin >> nr_1 >> nr_2;
        aux = GCD(nr_1, nr_2);
        v.push_back(aux);
    }
    
    fin.close();

    // afisarea
    for(int nr : v){
        fout << nr << '\n';
    }
    fout.close();
    return 0;
}