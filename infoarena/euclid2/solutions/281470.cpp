#include<fstream>
using namespace std;
int main() {
    long a, b;
    int i, T, r;
    fstream f("euclid2.in", ios::in);
    fstream g("euclid2.out", ios::out);
    f>>T;
    for(i=1; i<=T; i++) {
    f>>a>>b;
    while(b) {
    r=a%b;
    a=b;
    b=r;
}
    g<<a<<"\n";
}
    f.close();
    g.close();
    return 0;
}   
