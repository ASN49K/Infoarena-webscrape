#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int times;
    in >> times;

    int a, b, c;
    while (times--) {
        in >> a >> b;
        if (a < b) {
            c = a;
            a = b;
            b = c;
        }

        while (b) {
            c = a;
            a = b;
            b = c % b;
        }

//        cout << a << endl;
        out << a << '\n';
    }

    return 0;
}

