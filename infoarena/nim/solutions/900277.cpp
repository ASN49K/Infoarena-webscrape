#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t;
    f>>t;

    int nrp;
    for (int i = 1; i <= t; ++i) {
        f>>nrp;
        int s=0;
        int x;
        for (int j=1; j<=nrp; ++j) {
            f>>x;
            s^= x;
        }
        if (s==0) g<<"NU\n";
             else g<<"DA\n";
    }
    f.close(); g.close();
    return 0;
}
