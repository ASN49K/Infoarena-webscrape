#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n;
    in >> n;
    
    while(n) {
        --n;

        int a, b, c;
        in >> a >> b;

        while (b) {
            c = b % a;
            a = b;
            b = c;
        }
        out << a << '\n';
    }
    in.close();
    out.close();
    return 0;
}