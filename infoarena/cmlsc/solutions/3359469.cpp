#include <fstream>
#include <vector>

using namespace std;

void refac_subsirul(vector <vector <int> > &lung, vector <int> &v1, vector <int> &v2, int i1, int i2, ofstream &out) {
    if (lung[i1][i2] == 0) {
        return;
    }
    if (v1[i1] == v2[i2]) {
        refac_subsirul(lung, v1, v2, i1 - 1, i2 - 1, out);
        out << v1[i1] << " ";
    } else {
        if (lung[i1-1][i2] > lung[i1][i2-1]) {
            i1--;
        } else {
            i2--;
        }
        refac_subsirul(lung, v1, v2, i1, i2, out);
    }
}

int main() {
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int n1, n2;
    in >> n1 >> n2;
    vector <int> v1(n1 + 1);
    vector <int> v2(n2 + 1);
    for (int i = 1; i <= n1; i++) {
        in >> v1[i];
    }
    for (int i = 1; i <= n2; i++) {
        in >> v2[i];
    }
    in.close();
    vector <vector <int> > lung(n1 + 1, vector <int>(n2 + 1, 0));
    for (int i1 = 1; i1 <= n1; i1++) {
        for (int i2 = 1; i2 <= n2; i2++) {
            if (v1[i1] == v2[i2]) {
                lung[i1][i2] = 1 + lung[i1-1][i2-1];
            } else {
                lung[i1][i2] = max(lung[i1][i2-1], lung[i1-1][i2]);
            }
        }
    }
    out << lung[n1][n2] << "\n";
    refac_subsirul(lung, v1, v2, n1, n2, out);
    out << "\n";
    out.close();
    return 0;
}
