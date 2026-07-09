#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid(int x, int y){
    int r;
    while(y){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
    int t, x, y;
    fin >> t;
    while (t--){
        fin >> x >> y;
        fout << euclid(x, y) << "\n";
    }
    return 0;
}
