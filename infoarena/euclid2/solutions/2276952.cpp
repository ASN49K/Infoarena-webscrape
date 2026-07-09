#include <fstream>

using namespace std;

int n, i, a, b, r;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>a>>b;
        r = 0;
        while(b){
            r = a%b;
            a = b;
            b = r;
        }
        fout<<a<<"\n";
    }
    return 0;
}
