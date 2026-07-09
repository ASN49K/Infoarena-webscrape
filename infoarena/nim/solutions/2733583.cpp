#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t , n;

void solve()
{
    fin >> n;
    int XOR = 0;
    while(n --)
    {
        int x;
        fin >> x;
        XOR = XOR ^ x;
    }
    if(XOR == 0)
        fout << "NU" << '\n';
    else
        fout << "DA" << '\n';
}

int main() {

    fin >> t;
    while(t --)
        solve();
    return 0;
}