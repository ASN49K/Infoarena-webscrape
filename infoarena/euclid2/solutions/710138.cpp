#include <fstream>
#include <iostream>
using namespace std;

inline
int cmmdc(int a, int b) {
    int r;

    do {
        r = a % b;
        a = b;
        b = r;
    } while (r != 0);

    return a;
}

int main(int argc, char **argv) {
    int n;
    ifstream infile ("euclid2.in");
    ofstream outfile ("euclid2.out", ios::out);

    infile >> n;

    for (int i = 0 ; i < n ; i++) {
        int a, b;
        infile >> a >> b;

        outfile << cmmdc(a, b) << endl;
    }

	return 0;
}
