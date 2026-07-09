#include <fstream>

int gcd(int a, int b){
    if (!b){
        return a;
    }
    return gcd(b, a%b);
}

int main(){
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");
    int a,b,n;
    fin >> n;
    for (int i = 1; i <= n; i++){
        fin >> a >> b;
        fout << gcd(a,b) << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}