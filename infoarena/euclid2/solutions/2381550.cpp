#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
    int n, a, b, r;
    fin>>n;
    while(n > 0){
        fin>>a>>b;
        while(b != 0){
            r = a % b;
            a = b;
            b = r;
        }
        fout<<a<<"\n";
        --n;
    }
    fin.close();
    fout.close();
    return 0;
}
