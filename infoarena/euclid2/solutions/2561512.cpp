
#include <fstream>

using namespace std;

int CMMDC(int a, int b) {
    if (b == 0)
        return a;
    return CMMDC(b, a % b);
}

int main(void) {
    ifstream in;
    ofstream out;
    in.open ("euclid2.in");
    out.open ("euclid2.out");
    in.is_open();
    int n, a, b;
    in>>n;
    while (n)
    {
        in>>a>>b;
        out<<CMMDC(a,b)<<"\n";
        n--;
    }
    in.close();
    out.close();
    return 0;
    
}