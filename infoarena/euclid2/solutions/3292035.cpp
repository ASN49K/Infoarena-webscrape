#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T, i, a, b;
int main(){
    fin >> T;
    for(i; i < T; ++i){
        fin >> a >> b;
        while(b){
            int r = a % b;
            a = b;
            b = r;
        }
        fout << a << '\n';
    }
    fin.close();
    fout.close();
}
