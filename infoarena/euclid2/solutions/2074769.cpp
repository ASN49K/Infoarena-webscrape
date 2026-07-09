#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b){
    if(!b)
        return a;
    return euclid(b, a%b);
}

int main(){
    int n, a, b;
    fin >> n;
    while (n){
        fin >>a>>b;
        fout << euclid(a,b) << endl;
        n--;
    }
    fin.close();
    fout.close();
    return 0;
}
