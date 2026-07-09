#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int n;
    ifstream infile ("euclid2.in");
    ofstream outfile ("euclid2.out", ios::out);

    infile >> n;

    for (int i = 0 ; i < n ; i++) {
        int a, b, r;
        infile >> a >> b;

        do {
            r = a % b;
            a = b;
            b = r;
        } while (r);
        outfile << a << endl;
    }

	return 0;
}
