#include <fstream>
using namespace std;
int T, a, b, r, i;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
    fin>>T;
    for(i=1;i<=T;i++){
        fin>>a>>b;
        while(b != 0){
            r = a%b;
            a = b;
            b = r;
        }
        fout<<a<<"\n";
    }
}
