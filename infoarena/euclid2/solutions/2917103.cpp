#include <fstream>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ifstream in_file("euclid2.in");
    ofstream out_file("euclid2.out");

    if (in_file.is_open() && out_file.is_open()) {
        int n;

        in_file >> n;

        for (int i = 0; i < n; i++) {
            int a, b;
            in_file >> a >> b;

            out_file << gcd(a, b) << endl;
        }
    } else {
        cout << "Can't open file" << endl;
    }


    in_file.close();
    out_file.close();

    return 0;
}