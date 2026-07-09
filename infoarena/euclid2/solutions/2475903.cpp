#include <fstream>

long long cmmdc(long long x, long long y){
    long long temp;
    while( y != 0 ){
        temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

int main(){
    std :: ifstream fin("euclid2.in");
    std :: ofstream fout("euclid2.out");
    int n;
    fin >> n;
    for(int i = 0; i < n; i++){
        long long x, y;
        fin >> x >> y;
        fout << cmmdc(x, y) << std :: endl;
    }
    fin.close();
    fout.close();
    return 0;
}