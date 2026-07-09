#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    int a = 0, b = 0, t = 0;
    in >> t;
    for (int i = 0; i < t;i ++ ){
        in >> a >> b;
        out << cmmdc(a, b) << "\n";
    }
    return 0;
}
