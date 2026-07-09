using namespace std;
#include <fstream>
ifstream fin("nim.in");
ofstream fout("nim.out");


int main()
{
    int n, t, a, s;
    fin >> t;
    for(; t; --t)
    {
        fin >> n;
        for(s = 0; n; --n) {fin >> a; s ^= a;}
        if(s) fout << "DA\n";
        else fout << "NU\n";
    }
    return 0;
}
