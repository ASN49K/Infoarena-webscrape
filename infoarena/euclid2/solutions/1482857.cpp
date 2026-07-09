#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main(int argc, const char * argv[]) {
    int t; f >> t;
    int a;
    int b;
    int aux;
    while (t--){
        f >> a;
        f >> b;
        if (b > a) swap(a, b);
        while (b){
            aux = b;
            b = a % b;
            a = aux;
        }
        g << a << '\n';
    }
    f.close();
    g.close();
    return 0;
}
