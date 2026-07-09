#include <fstream>
int main(int argc, const char * argv[]) {
    using namespace std;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
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
        g << a << endl;
    }
    f.close();
    g.close();
    return 0;
}
