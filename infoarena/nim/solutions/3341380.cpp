#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int n, xx, xorr;
int solve(){
    in>>n; xorr = 0;
    for(int i = 1; i <= n; i++)
        in>>xx, xorr ^= xx;
    return (xorr == 0);
}

int main(){

    int tests = 0; in>>tests;
    for(int i = 1; i <= n; i++){
        out<<(solve() ? "DA\n" : "NU\n");
    }

    return 0;
}
