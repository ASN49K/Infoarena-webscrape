#include <fstream>

using namespace std;

short best[1025][1025];
short sir1[1025], sir2[1025], sol[1025];

short Max (short a, short b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    ifstream file_in ("cmlsc.in");
    ofstream file_out ("cmlsc.out");

    short l1, l2, poz = 0;
    short i, j;

    // Citirea datelor
    file_in >> l1 >> l2;
    for (i = 1; i <= l1; i++) {
        file_in >> sir1[i];
    }
    for (i = 1; i <= l2; i++) {
        file_in >> sir2[i];
    }

    // Calcularea solutiei
    for (i = 1; i <= l1; i++) {
        for (j = 1; j <= l2; j++) {
            if (sir1[i] == sir2[j]) {
                best[i][j] = best[i - 1][j - 1] + 1;
            } else {
                best[i][j] = Max (best[i - 1][j], best[i][j - 1]);
            }
        }
    }

    for (i = l1, j = l2; i > 0;) {
        if (sir1[i] == sir2[j]) {
            sol[poz++] = sir1[i];
            i--;
            j--;
        } else if (best[i][j - 1] > best[i - 1][j]) {
            j--;
        } else {
            i--;
        }
    }

    // Afisarea solutiei
    file_out << best[l1][l2] << "\n";

    for (i = poz - 1; i >= 0; i--) {
        file_out << sol[i] << " ";
    }

    return 0;
}
