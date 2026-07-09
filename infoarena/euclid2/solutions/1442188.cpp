#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, n;

int cmmdc(int x, int y){
    if (!y)
        return x;
    else
        return cmmdc(y, x%y);
}

int main(){
    fin >> n;
    for (int i = 1; i <= n; i++){
        fin >> a >> b;
        fout << cmmdc(a, b);
        fout << "\n";
    }
    return 0;
}
