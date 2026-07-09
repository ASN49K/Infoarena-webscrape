#include <fstream>
using namespace std;

void swap(int &a, int &b) {
    int x = a;
    a = b;
    b = x;
}


int cmmdc(int a, int b) {
    while (b != 0)
    {
        a = a%b;
        swap(a, b);
    }
    return a;

}

int main() {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int t, i, a, b;
    in >> t;
    for (i = 1; i <= t; i++)
    {
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }
}
