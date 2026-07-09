#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b){
    if(b == 0)
        return a;
    return euclid(b, a%b);
}

int main(){
    int T, a, b;
    fin >> T;
    for(int i=1;i<=T;i++){
        fin >> a >> b;
        fout << euclid(a, b) << "\n";
    }
    return 0;
}