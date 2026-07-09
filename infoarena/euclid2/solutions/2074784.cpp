#include <fstream>
using namespace std;
int n, a, b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b){
    if(!b)
        return a;
    return gcd(b, a%b);
}

int main(){
    fin >> n;
    while (n){
        fin >>a>>b;
        fout << gcd(a,b) << endl;
        n--;
    }
//    fin.close();
//    fout.close();
    return 0;
}
