#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

ifstream fin ("aria.in");
ofstream fout ("aria.out");

const int MAX = 1000000;
int n;
long double x[MAX + 5], y[MAX + 5];

int main() {
    int i;
    long double s = 0;

    fin >> n;
    for (i = 1; i <= n; i++)
        fin >> x[i] >> y[i];
    x[n + 1] = x[1];
    y[n + 1] = y[1];

    for (i = 1; i <= n; i++) 
        s += (x[i] * y[i + 1] - x[i + 1] * y[i]);

    fout << fixed << setprecision(5) << fabs(s / 2.0);

    fin.close();    
    fout.close();

    return 0;
}