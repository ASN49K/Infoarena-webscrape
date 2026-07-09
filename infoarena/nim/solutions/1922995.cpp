#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int p, i, j, x, n, rez;//partide
    f >> p;
    for(i = 1; i <= p; i++ ){
        f >> n;
        rez = 0;
        for(j = 1; j <= n; j++){
            f >> x;
            rez = (rez ^ x);
        }
        if(rez != 0)
            g << "DA";
        else
            g << "NU";
        g << '\n';
    }
    return 0;
}
