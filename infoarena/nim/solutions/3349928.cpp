#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main(){
    int t, n, x, s;

    fin >> t;
    while(t--){
        fin >> n;
        s = 0;
        while(n--){
            fin >> x; s ^= x;
        }
        fout << (s == 0? "NU\n": "DA\n");
    }

    fin.close();
    fout.close();
    return 0;
}