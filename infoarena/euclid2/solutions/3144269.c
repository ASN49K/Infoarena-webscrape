#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{
    int a, b, r, t;
    fin >> t;
    while (t){
    fin >> a >> b;
    while (b > 0){
        r = a % b;
        a = b;
        b = r;
    }
    fout << a;
    fout << endl;
    t--;
    }
    return 0;
}
