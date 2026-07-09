#include <fstream>
#include <cstring>
#include <vector>
#include <ctype.h>

using namespace std;

string text[151];
int dinam[151];
char d[32][32];

int MAX(int X, int Y) {
    return X > Y ? X : Y;
}

int subSir (int cuv1, int cuv2) {
    int i, j;

    for (i = 1; i <= text[cuv1].size(); i++) {
        for (j = 1; j <= text[cuv2].size(); j++) {
            if (text[cuv1][i - 1] == text[cuv2][j - 1]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            } else {
                d[i][j] = MAX(d[i][j - 1], d[i - 1][j]);
            }
        }
    }
    return d[text[cuv1].size()][text[cuv2].size()];
}

int sim (int cuv1, int cuv2) {
    int lSubSir = subSir(cuv1, cuv2);
    return text[cuv1].size() + text[cuv2].size() - (2 * lSubSir);
}

#include <iostream>

int main() {
    ifstream file_in ("lant.in");
    ofstream file_out ("lant.out");

    int k;
    int l;
    int i, j;
    char c;
    string stack;

    file_in >> k;
    //cout << k;
    int ind = -1;

    /*while (file_in >> sir) {
        l = strlen(sir);
        ind++;
        for (i = 0; i < l; i++) {
            if (sir[i] >= 'a' && sir[i] <= 'z') {
                text[ind].push_back(sir[i]);
            }
        }
    }*/

    while (!file_in.eof() && (c = file_in.get())) {
        //cout << c;
        if (islower(c)) {
            stack.push_back(c);
        } else if (!stack.empty()) {
            text[++ind] = stack;
            stack.clear();
        }
    }

    //cout << ind << '\n';

    for (i = ind; i >= 0; i--) {
        for (j = i + 1; j <= ind; j++) {
            if (sim(i, j) <= k) {
                dinam[i] += dinam[j];
            }
        }
        dinam[i] += dinam[i] == 0;
    }

    file_out << dinam[0] << "\n";

    return 0;
}
