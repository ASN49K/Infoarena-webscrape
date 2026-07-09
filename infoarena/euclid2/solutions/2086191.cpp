#include <iostream>
#include <fstream>

using namespace std;

int e(int a, int b) {
    int r;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n, a, b;
    in >> n;
    for(int i = 1;i <= n;i++) {
        in >> a >> b;
        out << e(a, b) << endl;
    }
    return 0;
}
