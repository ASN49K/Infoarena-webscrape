#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main(){
    int t, n, s, x;
    f >> t;
    while (t){
        f >> n;
        s = 0;
        while (n){
            f >> x;
            s ^= x;
            n--;
        }
        g << (s == 0 ? "NU\n" : "DA\n");
        t--;
    }
    return 0;
}
