#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream infile("nim.in");
    ofstream outfile("nim.out");

    if (!infile || !outfile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    int t;
    infile >> t;

    while (t--) {
        int n;
        infile >> n;
        vector<long long> heaps(n);
        long long nim_sum = 0;

        for (int i = 0; i < n; ++i) {
            infile >> heaps[i];
            nim_sum ^= heaps[i];
        }

        if (nim_sum == 0) {
            outfile << "NU" << endl;
        } else {
            outfile << "DA" << endl;
        }
    }

    infile.close();
    outfile.close();

    return 0;
}
