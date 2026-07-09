#include <fstream>
int main() {
    std::ifstream in("euclid2.in");
    std::ofstream out("euclid2.out");
    int nr,a,b;
    in >> nr;
    for(int i = 0; i < nr; i++) {
        in >> a >> b;
        while(a!=b)
            a>b?a-=b:b-=a;
        out << a << '\n';
    }
    return 0;
}
