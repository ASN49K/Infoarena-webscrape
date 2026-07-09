#include <fstream>
using namespace std;
int x,y,r,i,Teste;
int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>Teste;
    for (i=1;i<=Teste;i++) {
        fin>>x>>y;
        while (y!=0) {
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<"\n";
    }
    return 0;
}

