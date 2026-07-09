#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n, a, b;
    in >> n;
    int r = 1;
    for(int i = 1;i <= n;i++) {
        in >> a >> b;
        while(b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        out << a << endl;
    }
    return 0;
}
