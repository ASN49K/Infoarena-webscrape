#include <fstream>
#include <iostream>
int main() {
    std::ifstream in("euclid2.in");
    std::ofstream out("euclid2.out");
    int nr,a,b,c;
    in >> nr;
    for(int i = 0; i < nr; i++) {
        in >> a >> b;
        while(a!=0&&b!=0)
            a>b?a=a%b:b=b%a;
        out << b << '\n';
    }
    return 0;
}
