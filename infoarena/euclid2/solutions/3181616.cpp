#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t, a, b;

    fin >> t;
    while(t--){
        fin >> a >> b;
        fout << __gcd(a, b) << '\n';
    }

    return 0;
}
