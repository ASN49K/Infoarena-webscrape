#include <fstream>

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

using namespace std;

int main()
{   int x;
    fin >> x;
    int a, b, rest;
    for (int i = 1; i <= x; i++){
        fin >> a >> b;
        while (b != 0) {
           rest = a % b;
            a = b;
            b = rest;
        }
            fout << a << "/n";
    }
    return 0;
}
