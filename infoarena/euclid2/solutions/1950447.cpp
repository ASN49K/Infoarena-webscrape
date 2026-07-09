#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned cmmdc(int a, int b){
    if (!b)
        return a;
    return cmmdc(b, a % b);
}

int main(){
    unsigned n, a, b, i;
    fin >> n;
    for (i = 1; i <= n; i++){
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
