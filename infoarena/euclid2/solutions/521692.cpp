#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int times;
    in >> times;

    while (times--) {
        int a, b;
        in >> a >> b;
        if (a < b) {
            int c = a;
            a = b;
            b = c;
        }

        while (b) {
            int c = a;
            a = b;
            b = c % b;
        }

        cout << a << endl;
        out << a << endl;
    }

    return 0;
}

