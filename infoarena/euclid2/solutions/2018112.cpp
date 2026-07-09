# include <fstream>
# include <cmath>

using namespace std;

int euclid(int a, int b) {
    if (a == b) {
        return a;
    }

    int x = min(a, b);
    int y = max(a, b);

    return euclid(x, y - x);
}

int main () {
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");

    int t, a, b;

    for(fin>>t;t > 0; --t) {
        fin>>a>>b;

        fout<<euclid(a, b)<<"\n";
    }

    return 0;
}
