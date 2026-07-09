#include <fstream>
std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");
int cmmdc(int a, int b){
    if(b == 0)
        return a;
    return cmmdc(b, a % b);
}
int main(){
    int n;
   fin >> n;
    int x, y;
    for(int i = 1; i <= n; i++){
        fin >> x >> y;
        fout << cmmdc(std::max(x, y), std::min(x, y)) << "\n";
    }
}