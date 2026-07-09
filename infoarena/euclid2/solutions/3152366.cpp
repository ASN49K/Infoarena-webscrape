#include<fstream>

using namespace std;

int euclid(int a, int b) {
    if (b == 0) {
        return a;
    }

    return euclid(b, a % b);
}

int main() {
    ifstream read("euclid2.in");
    ofstream write("euclid2.out");

    int tests, a, b;
    read >> tests;
    while(tests > 0) {
        read >> a >> b;
        write << euclid(a, b) << "\n";

        tests--;
    }
}